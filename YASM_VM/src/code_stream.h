#ifndef _CODE_STREAM_H
#define _CODE_STREAM_H
#include "config.h"

typedef enum
{
    OUT_OF_RANGE = DIV_BY_ZERO,
    NO_ERROR,
    NO_CONNECTION,
    NO_RANGE
} ERRORS;


#ifdef __cplusplus
extern "C" {
#endif

#ifndef ARDUINO
static uint16_t range;
static uint8_t *vm_code;
#endif


ERRORS code_stream_init();
ERRORS getbyte(uint16_t pos, uint8_t * in);


#ifdef __cplusplus
}
#endif
#endif
