//
// Created by zorgatone on 22/10/2023.
//

#ifndef TIME_UTILS_H
#define TIME_UTILS_H

#include <time.h>

typedef long tstamp_t;

tstamp_t to_timestamp(time_t t);
time_t from_timestamp(tstamp_t ts);

#endif //TIME_UTILS_H
