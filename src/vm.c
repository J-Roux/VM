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

#define BINARY_OPERATION(TYPE, SIZE, OP )  TYPE op1, op2; \
pop_##SIZE(&op1); \
pop_##SIZE(&op2); \
push_##SIZE(op1 OP op2)

#define OP_TYPE(OPERATION, OP)  case OPERATION##_BYTE: \
  { \
    BINARY_OPERATION(uint8_t, byte, OP);  \
    break; \
  } \
  case OPERATION##_SBYTE:\
  {\
    BINARY_OPERATION(int8_t, byte, OP);\
    break;\
  }\
  case OPERATION##_SHORT:\
  {\
    BINARY_OPERATION(uint16_t, short, OP);\
    break;\
  }\
  case OPERATION##_SSHORT:\
  {\
    BINARY_OPERATION(int16_t, short, OP);\
    break;\
  }\
  case OPERATION##_INT:\
  {\
    BINARY_OPERATION(uint32_t, int, OP);\
    break;\
  }\
  case OPERATION##_SINT:\
  {\
    BINARY_OPERATION(int32_t, int, OP);\
    break;\
  }\
  case OPERATION##_LONG:\
  {\
    BINARY_OPERATION(uint64_t, long, OP);\
    break;\
  }\
  case OPERATION##_SLONG:\
  {\
    BINARY_OPERATION(int64_t, long, OP);\
    break;\
  }

RESULT execute_intruction(uint8_t *code, uint16_t *program_counter, uint16_t programm_size)
{
	RESULT result = SUCCESS;
	COMMANDS command = code[*program_counter];
	switch (command)
	{
    OP_TYPE(ADD, +);
    OP_TYPE(SUB, -);
    OP_TYPE(MUL, *);
    OP_TYPE(DIV, /);
    OP_TYPE(LT, < );
    OP_TYPE(LEQ, <= );
    OP_TYPE(GT, > );
    OP_TYPE(GEQ, >= );
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
