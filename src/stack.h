#ifndef _STACK_H
#define _STACK_H
#include "config.h"
#include "exception.h"
#ifdef RANGE_CHECK
#define RANGE_CHECK 1
extern jmp_buf ex_buf__;
#else 
#define RANGE_CHECK 0
#endif 
typedef POINTER_SIZE ptr_size;


#ifdef __cplusplus
extern "C" {
#endif

void push(u8 *ptr, ptr_size size);
void pop(u8 *ptr, ptr_size size);
void push_byte(u8 value);
void push_short(uint16_t value);
void push_int(u32 value);
void push_long(u64 value);

#ifdef __cplusplus
}
#endif
#endif
