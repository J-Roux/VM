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


ERRORS jmp(uint16_t* pc, uint16_t address);
RESULT get_u16(uint16_t* pos, uint16_t* data);
ERRORS code_stream_init(uint8_t count, ...);
ERRORS get_byte(uint16_t pos, uint8_t * in);


#ifdef __cplusplus
}
#endif
#endif
