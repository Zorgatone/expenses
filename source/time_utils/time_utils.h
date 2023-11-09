//
// Created by zorgatone on 22/10/2023.
//

#ifndef EXPENSES_MY_TIMEGM_H
#define EXPENSES_MY_TIMEGM_H

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

TIMET my_timegm(TM const *t);

TIMET time_add(TIMET t, long duration);

#ifdef __cplusplus
}
#endif

#undef TM
#undef TIMET

#endif //EXPENSES_MY_TIMEGM_H
