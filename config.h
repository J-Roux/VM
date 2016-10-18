#ifndef _CONFIG_H_
#define _CONFIG_H_
#include <stdint.h>
//#define DEBUG
#define RANGE_CHECK

#define STACK_SIZE 128
#define POINTER_SIZE int16_t


typedef uint8_t u8;
//typedef uint16_t u16;


#ifdef DEBUG
#define TRACE printf
#define MEMCPY(DEST, SRC, SIZE) memcpy(DEST, SRC, SIZE)
#else 
#include <string.h>
#include <Arduino.h>
#define TRACE Serial.println
#define MEMCPY(DEST, SRC, SIZE) memcpy(DEST, SRC, SIZE)
#endif

#ifndef RANGE_CHECK
#define TRACE(MESSAGE)
#endif

#endif /*_CONFIG_H_*/
