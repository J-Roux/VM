#include "stack.h"
#include "command.h"

typedef enum STATE
{
    COMMAND,
    GET_ARG,
    TERMINATE
} vm_state;

vm_state state = GET_ARG;
uint16_t arg;

typedef struct  
{
    uint8_t * data;
    uint16_t arg;
    uint8_t command;
} data_blob;

void command_proceed(uint8_t command, uint8_t* data)
{
    switch(command)
    {
  //     case MUL: break;
    }
}
uint64_t execute_step(data_blob data, uint8_t* code)
{
    uint64_t pointer = 0;
    switch(state)
    {
        case GET_ARG: 
        {
            push(code, data.arg);
            state = COMMAND;
            pointer += data.arg;
            break;
        }
        case COMMAND:
        {
    //        command_proceed(data.command);
            pointer++;
            break;
        }
        case TERMINATE:
        {
            break;
        }
    }
    return pointer;
}
