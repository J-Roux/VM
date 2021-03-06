#include "vm.h"
#include "code_stream.h"



static uint16_t pc = 0;

RESULT inc_pc(uint16_t offset)
{
        return jmp(&pc, pc + offset);
}


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


RESULT conditional_jmp(uint8_t condition)
{
        uint8_t op = 0;
        RESULT result = pop_byte(&op);
        if(op == condition)
        {
                uint16_t address;
                result |= get_u16(&pc, &address);
                jmp(&pc, address);
        }
        else
        {
                inc_pc(2);
        }
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

#define TYPE_BINARY_OPERATION_DIV(OPERATION, TYPE, SIZE) case OPERATION: { TYPE op1, op2; \
        result = pop_op_##SIZE(&op1, &op2); \
        result = op2 ? push_##SIZE(op1 / op2) : DIV_BY_ZERO; \
        break; \
        }

#define UNSIGNED_BINARY_OPERATION_DIV(OPERATION) TYPE_BINARY_OPERATION_DIV(OPERATION##_BYTE, uint8_t, byte) \
        TYPE_BINARY_OPERATION_DIV(OPERATION##_SHORT, uint16_t, short) \
        TYPE_BINARY_OPERATION_DIV(OPERATION##_INT, uint32_t, int) \
        TYPE_BINARY_OPERATION_DIV(OPERATION##_LONG, uint64_t, long)

#define SIGNED_BINARY_OPERATION_DIV(OPERATION) TYPE_BINARY_OPERATION_DIV(OPERATION##_SBYTE, int8_t, byte) \
        TYPE_BINARY_OPERATION_DIV(OPERATION##_SSHORT, int16_t, short) \
        TYPE_BINARY_OPERATION_DIV(OPERATION##_SINT, int32_t, int) \
        TYPE_BINARY_OPERATION_DIV(OPERATION##_SLONG, int64_t, long)

#define BINARY_OPERATION_DIV \
        UNSIGNED_BINARY_OPERATION_DIV(DIV)\
        SIGNED_BINARY_OPERATION_DIV(DIV)

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



#define BINARY_OPERATION(OPERATION, OP) \
        UNSIGNED_BINARY_OPERATION(OPERATION, OP)

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

typedef RESULT(*func)(uint8_t value);

RESULT push_by_arg( func mem_instruction)
{
        RESULT result = SUCCESS;
        uint8_t arg;
        uint8_t t;
          inc_pc(1);
        result = get_byte(pc, &arg);
        inc_pc(1);
        for(uint8_t i = 0; i < arg; i++)
        {
                get_byte(pc, &t);
                jmp(&pc, pc + 1);
                mem_instruction(t);
        }
        return result;
}

RESULT push_data( uint8_t size)
{
    RESULT result;
    uint8_t * data;
    //result |= get_code(data, size);
    result |= push(data, size);
    return result;
}


RESULT pop_data( uint8_t size)
{
    RESULT result;
    uint8_t * data;
   // result |= get_code(data,  size);
    result |= pop(data,  size);
    return result;
}


RESULT execute_intruction()
{
        RESULT result = SUCCESS;
        COMMANDS command = END;
        result = get_byte(pc, (uint8_t*)&command);
        switch (command)
        {
                UNSIGNED_BINARY_OPERATION(ADD, +);
                UNSIGNED_BINARY_OPERATION(SUB, -);
                UNSIGNED_BINARY_OPERATION(MUL, *);
                BINARY_OPERATION_DIV;
                UNSIGNED_BINARY_OPERATION(OR, |);
                UNSIGNED_BINARY_OPERATION(AND, &);
                UNSIGNED_BINARY_OPERATION(SHR, >>);
                UNSIGNED_BINARY_OPERATION(SHL, <<);
                COMPARE_BINARY_OPERATION(EQ, ==);
                COMPARE_BINARY_OPERATION(NEQ, !=);
                COMPARE_BINARY_OPERATION(LT, <);
                COMPARE_BINARY_OPERATION(GT, >);
                COMPARE_BINARY_OPERATION(LEQ, <=);
                COMPARE_BINARY_OPERATION(GEQ, >=);
                UNSIGNED_UNARY_OPERATION(INC, ++);
                UNSIGNED_UNARY_OPERATION(DEC, --);
                SIGNED_UNARY_OPERATION(NEG, -);
                UNSIGNED_UNARY_OPERATION(NOT, ~);
                UNSIGNED_UNARY_OPERATION(LNOT, !);
                case PUSH:
                {
                        result = push_by_arg( &push_byte);
                        break;
                }
                case POP:
                {
                        result = push_by_arg( &pop_byte);
                        break;
                }
                case PUSH_BYTE:
                {
                        result = push_data(sizeof(uint8_t));
                        break;
                }
                case PUSH_SHORT:
                {

                        result = push_data(sizeof(uint16_t));
                        break;
                }
                case PUSH_INT:
                {

                        result = push_data(sizeof(uint32_t));
                        break;
                }
                case PUSH_LONG:
                {

                        result = push_data(sizeof(uint64_t));
                        break;
                }
                case POP_BYTE:
                {

                        result = pop_data(sizeof(uint8_t));
                        break;
                }
                case POP_SHORT:
                {

                         result = pop_data(sizeof(uint16_t));
                        break;
                }
                case POP_INT:
                {

                         result = pop_data(sizeof(uint32_t));
                        break;
                }
                case POP_LONG:
                {
                        result = pop_data(sizeof(uint64_t));
                        break;
                }

                case JMP:
                {
                        uint16_t address;
                        result |= get_u16(&pc, &address);
                        result |= jmp(&pc, address);
                        break;
                }
                case JT:
                {
                        result = conditional_jmp(1);
                        break;
                }
                case JF:
                {
                        result = conditional_jmp(0);
                        break;
                }
                case END:
                {
                        pc = 0;
                        //reset();
                        result = CODE_END;
                        break;
                }
                case DUB:
                {
                        uint8_t size;
                        inc_pc(1);
                        result |= get_byte(pc, &size);
                        result |= dub(size);
                        inc_pc(1);
                        break;
                }
                case CALL:
                {
                        uint8_t id;
                        result |= get_byte(pc, &id);
                        switch(id)
                        {
                                case 0: PRINT(*(get_head(sizeof(uint8_t))));
                        }
                }

        }
        return SUCCESS;
}
