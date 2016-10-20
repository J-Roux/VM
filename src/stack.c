#include "stack.h"

u8 data[STACK_SIZE];
ptr_size pointer = 0;

void range_check(ptr_size size, ptr_size range)
{	
	if(RANGE_CHECK)
	{
		if( pointer  > range - size)
			THROW(STACK_OVERFLOW);
	}
}


void push(u8 *ptr, ptr_size size)
{

	range_check(size, STACK_SIZE);
	MEMCPY(data + pointer, ptr, size);
	pointer += size;
}

void pop(u8 *ptr, ptr_size size)
{
	range_check(size, 0);
	MEMCPY(ptr, data + pointer, size);
	pointer -= size;
}

void push_byte(u8 value)
{
	range_check(sizeof(u8), STACK_SIZE);
	data[++pointer] = value;
}

void push_short(uint16_t value)
{
	range_check(sizeof(uint16_t), STACK_SIZE);
	data[++pointer] = value;
	data[++pointer] = value >> 8;
}

void push_int(u32 value)
{
	range_check(sizeof(u32), STACK_SIZE);
	data[++pointer] = value;
	data[++pointer] = value >> 8;
	data[++pointer] = value >> 16;
	data[++pointer] = value >> 24;
}

void push_long(u64 value)
{
	push((u8*)&value, sizeof(u64));
}
