#include "vm.h"
#include "code_stream.h"

#include <stdio.h>
#include <stdlib.h>
#ifndef ARDUINO
int main(int argc, char** argv)
{
    int stop = 1;
    int i;
    if(argc < 2) {
      printf("No input file!\n");
      return 1;
    }
    FILE* f = fopen(argv[1], "r");
    fseek(f, 0L, SEEK_END);
    long int sz = ftell(f);
    rewind(f);
    uint8_t *code = malloc(sz);
    fread(code,1,sz, f);
    set_code(code, sz);
    while(stop)
    {
        RESULT result = execute_intruction();
        switch (result) {
        case STACK_OVERFLOW :
        {
            printf("stack overflow\n");

        }
        case CODE_END:
        {
            stop = 0;
        }
        }
    }
    return 0;
}
#endif
