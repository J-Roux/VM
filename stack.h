
#include "config.h"
#include "exception.h"
#ifdef RANGE_CHECK
#define RANGE_CHECK true
extern jmp_buf ex_buf__;
#else 
#define RANGE_CHECK false
#endif 
typedef POINTER_SIZE ptr_size;



void push(u8 *ptr, ptr_size size);