#include "code_stream.h"



RESULT get_code(uint8_t *)




#ifndef ARDUINO

ERRORS code_stream_init()
{
    return NO_ERROR;
}


ERRORS getbyte(uint16_t pos, uint8_t * in)
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
ERRORS init()
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
