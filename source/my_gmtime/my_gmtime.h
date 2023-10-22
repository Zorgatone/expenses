//
// Created by zorgatone on 22/10/2023.
//

#ifndef EXPENSES_MY_GMTIME_H
#define EXPENSES_MY_GMTIME_H

#ifdef __cplusplus

#include <ctime>
#define TIMET std::time_t
#define TM std::tm

extern "C" {

#else
#include <time.h>
#define TIMET time_t
#define TM struct tm
#endif

TIMET my_gmtime(TM const *t);

#ifdef __cplusplus
}
#endif

#undef TM
#undef TIMET

#endif //EXPENSES_MY_GMTIME_H
