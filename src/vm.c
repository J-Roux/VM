#include "vm.h"

typedef enum
{
	INSTRUCTION,
	ARG,
	EXEC,
	DATA,
	TERMINATE
}STATE;

STATE state = ARG;
uint16_t arg;



#define TYPE_BINARY_OPERATION (TYPE, SIZE, OP )  TYPE op1, op2; \
pop_##SIZE(&op1); \
pop_##SIZE(&op2); \
push_##SIZE(op1 OP op2)

#define BINARY_OPERATION(OPERATION, OP)  case OPERATION##_BYTE: \
  { \
    TYPE_BINARY_OPERATION(uint8_t, byte, OP);  \
    break; \
  } \
  case OPERATION##_SBYTE:\
  {\
    TYPE_OPERATION(int8_t, byte, OP);\
    break;\
  }\
  case OPERATION##_SHORT:\
  {\
    TYPE_OPERATION(uint16_t, short, OP);\
    break;\
  }\
  case OPERATION##_SSHORT:\
  {\
    TYPE_OPERATION(int16_t, short, OP);\
    break;\
  }\
  case OPERATION##_INT:\
  {\
    TYPE_OPERATION(uint32_t, int, OP);\
    break;\
  }\
  case OPERATION##_SINT:\
  {\
    TYPE_OPERATION(int32_t, int, OP);\
    break;\
  }\
  case OPERATION##_LONG:\
  {\
    TYPE_OPERATION(uint64_t, long, OP);\
    break;\
  }\
  case OPERATION##_SLONG:\
  {\
    TYPE_OPERATION(int64_t, long, OP);\
    break;\
  }

RESULT execute_intruction(uint8_t *code, uint16_t *program_counter, uint16_t programm_size)
{
	RESULT result = SUCCESS;
	COMMANDS command = code[*program_counter];
	switch (command)
	{
   	BINARY_OPERATION(ADD, +);
    	BINARY_OPERATION(SUB, -);
    	BINARY_OPERATION(MUL, *);
    	BINARY_OPERATION(DIV, /);
    	BINARY_OPERATION(LT, < );
    	BINARY_OPERATION(LEQ, <= );
    	BINARY_OPERATION(GT, > );
    	BINARY_OPERATION(GEQ, >= );
	}
	
	return result;
}

RESULT execute_step(uint8_t *code, uint16_t *program_counter, uint16_t programm_size)
{
	RESULT result = SUCCESS;
	switch (state)
	{
	case INSTRUCTION:
	{
		result = execute_intruction(code, program_counter, programm_size);
		break;
	}
	case ARG:
	{
		if (*program_counter + 2 < programm_size)
		{
			arg = *(uint16_t*)code;
			*program_counter += 2;
			result = SUCCESS;
		}
		else
			result = CODE_END;
		break;
	}
	

	case DATA:
		break;

	case TERMINATE:
		break;
	}
	return result;
}
