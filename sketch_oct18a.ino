#include "stack.h"

#ifdef DEBUG
#include "stdio.h"
#endif




void setup()
{
  TRY 
  {
    push(NULL, 256);
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

#ifdef DEBUG
int main()
{
  setup();
  return 0;
}
#endif
