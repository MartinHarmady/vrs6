

































#if   defined ( __ICCARM__ )
 #pragma system_include
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang system_header
#endif

#ifndef __CORE_CMINSTR_H
#define __CORE_CMINSTR_H









#if   defined ( __CC_ARM )
  #include "cmsis_armcc.h"


#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #include "cmsis_armcc_V6.h"


#elif defined ( __GNUC__ )
  #include "cmsis_gcc.h"


#elif defined ( __ICCARM__ )
  #include <cmsis_iar.h>


#elif defined ( __TMS470__ )
  #include <cmsis_ccs.h>


#elif defined ( __TASKING__ )







#elif defined ( __CSMC__ )
  #include <cmsis_csm.h>

#endif



#endif
