#include "stack.h"

uint8_t data[STACK_SIZE];
ptr_size pointer = 0;

RESULT range_check(ptr_size size, ptr_size range)
{	
		if( pointer  > range - size)
			return STACK_OVERFLOW;
    else
      return SUCCESS;
}


RESULT push(uint8_t *ptr, ptr_size size)
{
  RESULT result = SUCCESS;
  if(RANGE_CHECK)
	  result = range_check(size, STACK_SIZE);
	MEMCPY(data + pointer, ptr, size);
	pointer += size;
  return result;
}

RESULT pop(uint8_t *ptr, ptr_size size)
{
  RESULT result = SUCCESS;
  if(RANGE_CHECK)
	   result = range_check(size, 0);
	MEMCPY(ptr, data + pointer, size);
	pointer -= size;
  return result;
}

RESULT push_byte(uint8_t value)
{
  RESULT result = SUCCESS;
  if(RANGE_CHECK)
	  result = range_check(sizeof(uint8_t), STACK_SIZE);
	data[++pointer] = value;
  return result;
}

RESULT push_short(uint16_t value)
{
  RESULT result = SUCCESS;
  if(RANGE_CHECK)
	  result = range_check(sizeof(uint16_t), STACK_SIZE);
	data[++pointer] = value;
	data[++pointer] = value >> 8;
  return result;
}

RESULT push_int(uint32_t value)
{
  RESULT result = SUCCESS;
  if(RANGE_CHECK)
	  result =range_check(sizeof(uint32_t), STACK_SIZE);
	data[++pointer] = value;
	data[++pointer] = value >> 8;
	data[++pointer] = value >> 16;
	data[++pointer] = value >> 24;
  return result;
}

RESULT push_long(uint64_t value)
{
	  return push((uint8_t*)&value, sizeof(uint64_t));
}
