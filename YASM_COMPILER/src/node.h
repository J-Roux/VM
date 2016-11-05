#include <stdint.h>
#include <memory.h>
#include <stdlib.h>

static uint8_t* data;
static uint16_t pointer = 0;

void push(uint8_t* ptr, uint8_t size)
{
    data = realloc(data, pointer + size);
    memcpy(data + pointer, ptr, size);
    pointer += size;
}

void push_byte(uint8_t value)
{
    push(&value, sizeof(uint8_t));
}


void push_short(uint16_t value)
{
    push((uint8_t *)&value, sizeof(uint16_t));
}

void push_int(uint32_t value)
{
    push((uint8_t *)&value, sizeof(uint32_t));
}


void push_long(uint64_t value)
{
    push((uint8_t *)&value, sizeof(uint64_t));
}

void push_value(uint64_t value)
{
    printf("%i\n", value);
    if(value <= INT8_MAX){
        push_byte(value);
    } else if (value <= INT16_MAX){
        push_short(value);
    } else if (value <= INT32_MAX){
        push_int(value);
    } else {
        push_long(value);
    }
}
