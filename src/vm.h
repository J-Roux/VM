#ifndef _VM_H
#define _VM_H

#include "stack.h"
#include "command.h"

#ifdef __cplusplus
extern "C" {
#endif
RESULT execute_step(uint8_t *code, uint16_t *program_counter);

#ifdef __cplusplus
}
#endif
#endif