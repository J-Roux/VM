
#include "stack.h"




#ifndef ARDUINO
#include <assert.h>
#include <stdlib.h>




int main()
{

    
  uint8_t out_byte = 0;
  uint8_t in_byte = 1;

  assert(push_byte(in_byte) == SUCCESS);
  assert(pop_byte(&out_byte) == SUCCESS);
  ptr_size pointer = get_pointer();
  assert(pointer == -1);
  assert(out_byte == in_byte);
  in_byte = 2;
  out_byte = 3;
  assert(push(&in_byte, sizeof(in_byte)) == SUCCESS);
  assert(pop(&out_byte, sizeof(out_byte)) == SUCCESS);
  pointer = get_pointer();
  assert(pointer == -1);
  assert(out_byte == in_byte);
  
  uint16_t out_short = 4;
  uint16_t in_short = 5;  
  assert(push_short(in_short) == SUCCESS);
  assert(pop_short(&out_short) == SUCCESS);
  pointer = get_pointer();
  assert(pointer == -1);
  assert(out_short == in_short);
  out_short = 6;
  in_short = 7;
  assert(push((uint8_t*)&in_short, sizeof(in_short)) == SUCCESS);
  assert(pop((uint8_t*)&out_short, sizeof(out_short)) == SUCCESS);
  pointer = get_pointer();
  assert(pointer == -1);
  assert(out_short == in_short);
  
  uint32_t out_int = 9;
  uint32_t in_int = 10;  
  assert(push_int(in_int) == SUCCESS);
  assert(pop_int(&out_int) == SUCCESS);
  pointer = get_pointer();
  assert(pointer == -1);
  assert(out_int == in_int);
  in_int = 11;
  out_int = 12;
  assert(push((uint8_t*)&in_int, sizeof(in_int)) == SUCCESS);
  assert(pop((uint8_t*)&out_int, sizeof(out_int)) == SUCCESS);
  pointer = get_pointer();
  assert(pointer == -1);
  assert(out_int == in_int);
  
  uint64_t out_long = 13;
  uint64_t in_long = 14;  
  assert(push_long(in_long) == SUCCESS);
  assert(pop_long(&out_long) == SUCCESS);
  pointer = get_pointer();
  assert(pointer == -1);
  assert(out_long == in_long);
  in_long = 15;
  out_long = 16;
  assert(push((uint8_t*)&in_long, sizeof(in_long)) == SUCCESS);
  assert(pop((uint8_t*)&out_long, sizeof(out_long)) == SUCCESS);
  pointer = get_pointer();
  assert(pointer == -1);
  assert(out_long == in_long);
  
  uint8_t * ptr = (uint8_t *)calloc(STACK_SIZE, sizeof(uint8_t));
  int16_t stack_size = STACK_SIZE;
  assert(push(ptr, stack_size) == SUCCESS);

  stack_size++;
  assert(push(ptr, stack_size) == STACK_OVERFLOW);
  

  return 0;
}
#else

#endif






