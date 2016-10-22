#include "stack.h"

static uint8_t data[STACK_SIZE];
static ptr_size pointer = -1;

ptr_size get_pointer() { return pointer;}


RESULT range_check(ptr_size size, ptr_size range)
{	
    if( pointer  > range - size - 1)
      return STACK_OVERFLOW;
    else
      return SUCCESS;
}


RESULT push(uint8_t *ptr, ptr_size size)
{
  RESULT result = SUCCESS;
  if(RANGE_CHECK)
	  result = range_check(size, STACK_SIZE);
  MEMCPY(data + ++pointer, ptr, size);
  pointer += size - 1;
  return result;
}

RESULT pop(uint8_t *ptr, ptr_size size)
{
  RESULT result = SUCCESS;
  if(RANGE_CHECK)
	   result = range_check( -size, 0);
  pointer -= size - 1;
  MEMCPY(ptr, data + pointer, size);
  pointer--;    
  return result;
}


RESULT push_byte(uint8_t value) { return push((uint8_t *)&value, sizeof(uint8_t)); }
RESULT push_short(uint16_t value) { return push((uint8_t *)&value, sizeof(uint16_t)); }
RESULT push_int(uint32_t value) {  return push((uint8_t *)&value, sizeof(uint32_t));}
RESULT push_long(uint64_t value) {  return push((uint8_t *)&value, sizeof(uint64_t)); }



RESULT pop_byte(uint8_t *value) { return pop((uint8_t *)value, sizeof(uint8_t)); }
RESULT pop_short(uint16_t *value)  { return pop((uint8_t *)value, sizeof(uint16_t)); }
RESULT pop_int(uint32_t *value)  {  return pop((uint8_t *)value, sizeof(uint32_t));}
RESULT pop_long(uint64_t *value) {  return pop((uint8_t *)value, sizeof(uint64_t)); }




