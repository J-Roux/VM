#ifndef _CONFIG_H_
#define _CONFIG_H_
#include <stdint.h>


#define DEBUG

#define RANGE_CHECK

#define STACK_SIZE 128
#define POINTER_SIZE int16_t


typedef uint8_t u8;

typedef uint32_t u32;
typedef uint64_t u64;

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

#endif /*_CONFIG_H_*/
