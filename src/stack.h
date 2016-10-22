#ifndef _STACK_H
#define _STACK_H
#include "config.h"

#ifdef RANGE_CHECK
#define RANGE_CHECK 1

#else 
#define RANGE_CHECK 0
#endif 
typedef POINTER_SIZE ptr_size;

typedef enum 
{
  SUCCESS, 
  STACK_OVERFLOW = 2,
  CODE_END = 4
} RESULT;


#ifdef __cplusplus
extern "C" {
#endif

RESULT push(uint8_t *ptr, ptr_size size);
RESULT pop(uint8_t *ptr, ptr_size size);


RESULT push_byte(uint8_t value);
RESULT push_short(uint16_t value);
RESULT push_int(uint32_t value);
RESULT push_long(uint64_t value);

RESULT pop_byte(uint8_t *value);
RESULT pop_short(uint16_t *value);
RESULT pop_int(uint32_t *value);
RESULT pop_long(uint64_t *value);

ptr_size get_pointer();


#ifdef __cplusplus
}
#endif
#endif
