//
// Created by zorgatone on 22/10/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "timestamp.h"
#include "time_utils/time_utils.h"

#define YEAR_SECONDS

tstamp_t to_timestamp(time_t t) {
    struct tm epoch_tm = { .tm_year = 70, .tm_mday = 1 };
    time_t epoch_t = my_timegm(&epoch_tm);

    return (tstamp_t) difftime(t, epoch_t);
}

// Try with this approach: https://stackoverflow.com/a/74413214/1255826
time_t from_timestamp(tstamp_t ts) {
    struct tm epoch_tm = { .tm_year = 70, .tm_mday = 1 };
    time_t epoch_t = my_timegm(&epoch_tm);

    if (ts == 0) {
        return epoch_t;
    }

    return time_add(epoch_t, (long) ts);
}
