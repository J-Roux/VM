
#include "config.h"
#include "exception.h"
#ifdef RANGE_CHECK
#define RANGE_CHECK 1
extern jmp_buf ex_buf__;
#else 
#define RANGE_CHECK 0
#endif 
typedef POINTER_SIZE ptr_size;



void push(u8 *ptr, ptr_size size);
void pop(u8 *ptr, ptr_size size);