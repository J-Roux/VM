#ifndef _CODE_STREAM_H
#define _CODE_STREAM_H
#include "config.h"

static uint16_t pc = 0;
static uint8_t * data;

#ifdef __cplusplus
extern "C" {
#endif
RESULT inc_pc(uint8_t value);
RESULT get_code(uint8_t* ptr, uint16_t size);
uint16_t get_pc();
RESULT jmp(uint16_t pos);
void set_code(uint8_t *data, uint16_t size);
#ifdef __cplusplus
}
#endif
#endif
