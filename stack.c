#include "stack.h"

u8 data[STACK_SIZE];
ptr_size pointer = 0;

void range_check(ptr_size size, ptr_size range)
{
	if(pointer + size > range)
		THROW(STACK_OVERFLOW);	
}


void push(u8 *ptr, ptr_size size)
{
	if(RANGE_CHECK)
		range_check(size, STACK_SIZE);
	MEMCPY(data + pointer, ptr, size);
	pointer += size;
}

void pop(u8 *ptr, ptr_size size)
{
	if(RANGE_CHECK)
		range_check(-size, 0);
	MEMCPY(ptr, data + pointer, size);
	pointer -= size;

}
