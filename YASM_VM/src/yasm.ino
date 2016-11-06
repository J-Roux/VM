#include "vm.h"
#include <Serial.h>
RESULT result = SUCCESS;


void setup() {
  Serial.begin(9600);
}

void loop() {
   result = execute_intruction();
   switch(result)
   {
    case STACK_OVERFLOW:
        Serial.println("stack overflow");
        break;
   }
}
