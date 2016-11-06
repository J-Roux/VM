#ifndef _CONFIG_H_
#define _CONFIG_H_
#include <stdint.h>
#include "CMakeConfig.h"

#define DEBUG

#define POINTER_SIZE int16_t




#ifdef ARDUINO
#include <string.h>
#include <Arduino.h>
#define TRACE_DBG Serial.println
#define MEMCPY_DBG(DEST, SRC, SIZE) memcpy(DEST, SRC, SIZE)
#else
#define TRACE_DBG printf
#define MEMCPY_DBG(DEST, SRC, SIZE) memcpy(DEST, SRC, SIZE)
#endif


#ifdef DEBUG
#define TRACE TRACE_DBG
#define MEMCPY(DEST, SRC, SIZE) MEMCPY_DBG(DEST, SRC, SIZE)
#else 
#define TRACE
#define MEMCPY(DEST, SRC, SIZE)
#endif

#ifndef RANGE_CHECK
#define TRACE(MESSAGE)
#endif


typedef enum
{
  SUCCESS,
  STACK_OVERFLOW = 2,
  CODE_END = 4,
  DIV_BY_ZERO = 8,
} RESULT;


#endif /*_CONFIG_H_*/
