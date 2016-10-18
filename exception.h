#ifndef _TRY_THROW_CATCH_H_
#define _TRY_THROW_CATCH_H_
#include "config.h"

#ifdef RANGE_CHECK
#include <setjmp.h>
extern jmp_buf ex_buf__;
#define TRY do {  switch( setjmp(ex_buf__) ) { case 0: while(1) {
#define CATCH(x) break; case x:
#define FINALLY break; } default: {
#define ETRY break; } } }while(0)
#define THROW(x) longjmp(ex_buf__, x)
#define STACK_OVERFLOW (1)

#else 
#define TRY
#define CATCH(x)
#define FINALLY
#define ETRY
#define THROW(x)
#define STACK_OVERFLOW
#endif


#endif /*!_TRY_THROW_CATCH_H_*/