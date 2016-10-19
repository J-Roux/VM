
#include "stack.h"




void setup()
{
  TRY 
  {
    //u8 *ptr = 0;
    //push(ptr, 256);
    //pop(ptr,23);
  }
  CATCH (STACK_OVERFLOW)
  {
    TRACE("Stack overflow!\n");
  }
  ETRY;
}

void loop()
{


}

// push 2 1
// push 2 1
// mul


#ifndef ARDUINO
int main()
{
  setup();
  return 0;
}
#endif
