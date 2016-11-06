#ifndef _CONFIG_H_
#define _CONFIG_H_
#include <stdint.h>
#include "CMakeConfig.h"

#define DEBUG

#define POINTER_SIZE int16_t
#define BUFFER_SIZE 32



#ifdef ARDUINO
#include <string.h>
#include <Arduino.h>
#define PRINT Serial.println
#define MEMCPY_DBG(DEST, SRC, SIZE) memcpy(DEST, SRC, SIZE)
#else
#define PRINT(VALUE) printf("%i\n", VALUE)
#define MEMCPY_DBG(DEST, SRC, SIZE) memcpy(DEST, SRC, SIZE)
#endif

#define MEMCPY(DEST, SRC, SIZE) MEMCPY_DBG(DEST, SRC, SIZE)



typedef enum
{
  SUCCESS,
  STACK_OVERFLOW = 2,
  CODE_END = 4,
  DIV_BY_ZERO = 8,
} RESULT;


#endif /*_CONFIG_H_*/
