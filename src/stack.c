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
  result = push_byte(value);
  result += push_byte(value >> 8);
  return result;
}

RESULT push_int(uint32_t value)
{
  RESULT result = SUCCESS;
  result = push_short(value);
  result += push_short(value >> 16);
  return result;
}

RESULT push_long(uint64_t value)
{
  RESULT result = SUCCESS;
  result = push_int(value);
  result += push_int(value >> 32);
  return result;
}
RESULT pop_byte(uint8_t &value)
{
  RESULT result = SUCCESS;
  if(RANGE_CHECK)
    result = range_check(sizeof(uint8_t), 0);
  value = data[pointer--];
  return result;
}

RESULT pop_short(uint16_t &value)
{
  RESULT result = SUCCESS;
  result = pop_byte(value);
  result += pop_byte(value << 8);
  return result;
}

RESULT pop_int(uint32_t &value)
{
  RESULT result = SUCCESS;
  result = pop_short(value);
  result += pop_short(value << 16);
  return result;
}

RESULT pop_long(uint64_t &value)
{
  RESULT result = SUCCESS;
  result = pop_int(value);
  result += pop_int(value << 32);
  return result;
}


