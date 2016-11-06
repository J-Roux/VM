#include "code_stream.h"


#ifndef ARDUINO
#include <stdlib.h>
#include <memory.h>
RESULT inc_pc(uint8_t value)
{
    pc += value;
    return SUCCESS;
}

RESULT get_code(uint8_t* ptr, uint16_t size)
{
    memcpy(ptr, data + pc , size);
    pc += size;
    return SUCCESS;
}

uint16_t get_pc()
{
    return pc;
}

RESULT jmp(uint16_t pos)
{
    pc = pos;
}

void set_code(uint8_t* ptr, uint16_t size)
{
    data = realloc(data, size);
    memcpy(data, ptr, size);
}
#else
#include <Arduino.h>

RESULT inc_pc(uint8_t value)
{
    pc += value;
    return SUCCESS;
}

RESULT get_code(uint8_t* ptr, uint16_t size)
{

    return SUCCESS;
}

uint16_t get_pc()
{
    return pc;
}

RESULT jmp(uint16_t pos)
{
    pc = pos;
}

void set_code(uint8_t* ptr, uint16_t size)
{


}

#endif
