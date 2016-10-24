#include "vm.h"


uint16_t arg;



RESULT pop_op_byte(uint8_t* op1, uint8_t* op2)
{
  RESULT result = pop_byte(op1);
  result |= pop_byte(op2);
  return result;
}

RESULT pop_op_short(uint16_t* op1, uint16_t* op2)
{
  RESULT result = pop_short(op1);
  result |= pop_short(op2);
  return result;
}

RESULT pop_op_int(uint32_t* op1, uint32_t* op2)
{
  RESULT result = pop_int(op1);
  result |= pop_int(op2);
  return result;
}

RESULT pop_op_long(uint64_t* op1, uint64_t* op2)
{
  RESULT result = pop_long(op1);
  result |= pop_long(op2);
  return result;
}

#define TYPE_COMPARE_BINARY_OPERATION(OPERATION, TYPE, SIZE, OP ) case OPERATION: {  TYPE op1, op2; \
result = pop_op_##SIZE(&op1, &op2);\
result |= push_byte(op1 OP op2); \
break;\
}


#define TYPE_BINARY_OPERATION(OPERATION, TYPE, SIZE, OP ) case OPERATION: {  TYPE op1, op2; \
result = pop_op_##SIZE(&op1, &op2);\
result |= push_##SIZE(op1 OP op2); \
break;\
}



#define UNSIGNED_COMPARE_BINARY_OPERATION(OPERATION, OP) TYPE_COMPARE_BINARY_OPERATION(OPERATION##_BYTE, uint8_t, byte, OP) \
TYPE_COMPARE_BINARY_OPERATION(OPERATION##_SHORT, uint16_t, short, OP) \
TYPE_COMPARE_BINARY_OPERATION(OPERATION##_INT, uint32_t, int, OP) \
TYPE_COMPARE_BINARY_OPERATION(OPERATION##_LONG, uint64_t, long, OP) 

#define SIGNED_COMPARE_BINARY_OPERATION(OPERATION, OP) TYPE_COMPARE_BINARY_OPERATION(OPERATION##_SBYTE, int8_t, byte, OP) \
TYPE_COMPARE_BINARY_OPERATION(OPERATION##_SSHORT, int16_t, short, OP) \
TYPE_COMPARE_BINARY_OPERATION(OPERATION##_SINT, int32_t, int, OP) \
TYPE_COMPARE_BINARY_OPERATION(OPERATION##_SLONG, int64_t, long, OP) 

#define UNSIGNED_BINARY_OPERATION(OPERATION, OP) TYPE_BINARY_OPERATION(OPERATION##_BYTE, uint8_t, byte, OP) \
TYPE_BINARY_OPERATION(OPERATION##_SHORT, uint16_t, short, OP) \
TYPE_BINARY_OPERATION(OPERATION##_INT, uint32_t, int, OP) \
TYPE_BINARY_OPERATION(OPERATION##_LONG, uint64_t, long, OP) 

#define SIGNED_BINARY_OPERATION(OPERATION, OP) TYPE_BINARY_OPERATION(OPERATION##_SBYTE, int8_t, byte, OP) \
TYPE_BINARY_OPERATION(OPERATION##_SSHORT, int16_t, short, OP) \
TYPE_BINARY_OPERATION(OPERATION##_SINT, int32_t, int, OP) \
TYPE_BINARY_OPERATION(OPERATION##_SLONG, int64_t, long, OP) 

#define BINARY_OPERATION(OPERATION, OP) \
UNSIGNED_BINARY_OPERATION(OPERATION, OP)\
SIGNED_BINARY_OPERATION(OPERATION, OP)
        
#define COMPARE_BINARY_OPERATION(OPERATION, OP) \
UNSIGNED_COMPARE_BINARY_OPERATION(OPERATION, OP) \
SIGNED_COMPARE_BINARY_OPERATION(OPERATION, OP) 

#define TYPE_UNARY_OPERATION(OPERATION, TYPE, SIZE, OP ) case OPERATION: {TYPE op1; \
result = pop_##SIZE(&op1); \
result |= push_##SIZE(OP op1); \
break;\
}

#define UNSIGNED_UNARY_OPERATION(OPERATION, OP) TYPE_UNARY_OPERATION(OPERATION##_BYTE, uint8_t, byte, OP) \
TYPE_UNARY_OPERATION(OPERATION##_SHORT, uint16_t, short, OP) \
TYPE_UNARY_OPERATION(OPERATION##_INT, uint32_t, int, OP) \
TYPE_UNARY_OPERATION(OPERATION##_LONG, uint64_t, long, OP) 

#define SIGNED_UNARY_OPERATION(OPERATION, OP) TYPE_UNARY_OPERATION(OPERATION##_SBYTE, int8_t, byte, OP) \
TYPE_UNARY_OPERATION(OPERATION##_SSHORT, int16_t, short, OP) \
TYPE_UNARY_OPERATION(OPERATION##_SINT, int32_t, int, OP) \
TYPE_UNARY_OPERATION(OPERATION##_SLONG, int64_t, long, OP) 

#define UNARY_OPERATION(OPERATION, OP) \
UNSIGNED_UNARY_OPERATION(OPERATION, OP)\
SIGNED_UNARY_OPERATION(OPERATION, OP)

typedef RESULT(*func)(uint8_t *ptr, ptr_size size);

RESULT push_by_arg(  uint8_t *code, uint16_t *program_counter,  func mem_instruction)
{
       (*program_counter)++;
       uint8_t* ptr_data = code + *(program_counter) + 1;
       uint8_t arg = code[*program_counter];
       (*program_counter) += arg + 1;
       return mem_instruction(ptr_data, arg);
}
RESULT execute_intruction(uint8_t *code, uint16_t *program_counter)
{
	RESULT result = SUCCESS;
	COMMANDS command = code[*program_counter];
	switch (command)
	{
            BINARY_OPERATION(ADD, +);
            BINARY_OPERATION(SUB, -);
            BINARY_OPERATION(MUL, *);
            BINARY_OPERATION(DIV, /);
            UNSIGNED_BINARY_OPERATION(OR, |);
            UNSIGNED_BINARY_OPERATION(AND, &);
            UNSIGNED_BINARY_OPERATION(SHR, >>);
            UNSIGNED_BINARY_OPERATION(SHL, <<);
            UNSIGNED_COMPARE_BINARY_OPERATION(EQ, ==);
            UNSIGNED_COMPARE_BINARY_OPERATION(NEQ, !=);
            COMPARE_BINARY_OPERATION(LT, <);
            COMPARE_BINARY_OPERATION(GT, >);
            COMPARE_BINARY_OPERATION(LEQ, <=);
            COMPARE_BINARY_OPERATION(GEQ, >=);
            UNARY_OPERATION(INC, ++);
            UNARY_OPERATION(DEC, --);
            SIGNED_UNARY_OPERATION(NEG, -);
            UNSIGNED_UNARY_OPERATION(NOT, ~);
            case PUSH:
            {
                result = push_by_arg(code, program_counter, &push);
                break;
            }
            case POP:
            {
                result = push_by_arg(code, program_counter, &pop);
                break;
            }
            case PUSH_BYTE:
            {
                (*program_counter)++;
                result = push(code + (*program_counter), sizeof(uint8_t));
                break;
            }
            case PUSH_SHORT:
            {
                *program_counter++;
                result = push(code + (*program_counter), sizeof(uint16_t));
                break;
            }
            case PUSH_INT:
            {
                *program_counter++;
                result = push(code + (*program_counter), sizeof(uint32_t));
                break;
            }
            case PUSH_LONG:
            {
                *program_counter++;
                result = push(code + *program_counter, sizeof(uint64_t));
                break;
            }
 	}
	
	return result;
}

RESULT execute_step(uint8_t *code, uint16_t *program_counter)
{
	RESULT result = SUCCESS;
    result = execute_intruction(code, program_counter);
    (*program_counter)++;
	return result;
}
