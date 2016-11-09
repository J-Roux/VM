#include "code_stream.h"
#include <stdarg.h>



RESULT get_u16(uint16_t* pc, uint16_t* data)
{
        uint8_t in;
        get_byte(*pc, &in);
        *data = in << 8;
        jmp(pc, *pc + 1);
        get_byte(*pc, &in);
        *data = in;
        return SUCCESS;
}





#ifndef ARDUINO

uint16_t range;
uint8_t* vm_code;

ERRORS code_stream_init(uint8_t count, ...)
{
	va_list args;
	va_start(args, count);
        vm_code = va_arg(args, uint8_t*);
	range = va_arg(args, uint16_t);

	va_end(args);
    return NO_ERROR;
}

ERRORS jmp(uint16_t* pc, uint16_t address)
{
        if(*pc < range)
        {
            *pc = address;
            return NO_ERROR;
        }
        else
        {
            return OUT_OF_RANGE;
        }
}


ERRORS get_byte(uint16_t pos, uint8_t * in)
{
	
    if(pos < range)
    {
        *in = vm_code[pos];
        return NO_ERROR;
    }
    else
    {
        *in = 0xFF;
        return OUT_OF_RANGE;
    }
}


#else
#include <Arduino.h>

static uint16_t range;
ERRORS code_stream_init(uint8_t count, ...)
{

    while(Serial.available() <= 0)
    int income = Serial.read();
    if(income != -1)
    {
        range = income;
        return NO_ERROR;
    }
    else
    {
        return NO_RANGE;
    }

}

ERRORS getbyte(uint8_t pos, uint8_t * in)
{
    Serial.write(pos);
    while(Serial.available() <=0);
    if(income != -1)
    {
        range = income;
        return NO_ERROR;
    }
    else
    {
        return NO_CONNECTION;
    }
}

#endif
