//
// Created by zorgatone on 22/10/2023.
//

#ifndef EXPENSES_TIME_UTILS_H
#define EXPENSES_TIME_UTILS_H

#include <time.h>

typedef long long tstamp_t;

tstamp_t to_timestamp(time_t t);
time_t from_timestamp(tstamp_t ts);

#endif //EXPENSES_TIME_UTILS_H
