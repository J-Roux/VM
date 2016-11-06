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




#if !defined (get16bits)
#define get16bits(d) ((((uint32_t)(((const uint8_t *)(d))[1])) << 8)\
                       +(uint32_t)(((const uint8_t *)(d))[0]) )
#endif


uint32_t SuperFastHash (const char * data, int len) {
uint32_t hash = len, tmp;
int rem;

    if (len <= 0 || data == NULL) return 0;

    rem = len & 3;
    len >>= 2;

    /* Main loop */
    for (;len > 0; len--) {
        hash  += get16bits (data);
        tmp    = (get16bits (data+2) << 11) ^ hash;
        hash   = (hash << 16) ^ tmp;
        data  += 2*sizeof (uint16_t);
        hash  += hash >> 11;
    }

    /* Handle end cases */
    switch (rem) {
        case 3: hash += get16bits (data);
                hash ^= hash << 16;
                hash ^= ((signed char)data[sizeof (uint16_t)]) << 18;
                hash += hash >> 11;
                break;
        case 2: hash += get16bits (data);
                hash ^= hash << 11;
                hash += hash >> 17;
                break;
        case 1: hash += (signed char)*data;
                hash ^= hash << 10;
                hash += hash >> 1;
    }

    /* Force "avalanching" of final 127 bits */
    hash ^= hash << 3;
    hash += hash >> 5;
    hash ^= hash << 4;
    hash += hash >> 17;
    hash ^= hash << 25;
    hash += hash >> 6;

    return hash;
}

struct pair
{
uint16_t hash;
uint16_t value;
struct pair * left;
} begin;




void add_to_map(char * key, uint16_t value)
{
    uint16_t hash = SuperFastHash(key, strlen(key));
    struct pair * ptr = &begin;
    while(ptr->left != NULL)
    {
        ptr = ptr->left;
    }
    ptr->left = malloc(sizeof(struct pair));
    ptr->hash = hash;
    ptr->value = value;
}





