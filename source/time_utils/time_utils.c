//
// Created by zorgatone on 22/10/2023.
//

#include <stdio.h>
#include <stdlib.h>

#include "time_utils.h"
#include "my_timegm/my_timegm.h"

tstamp_t to_timestamp(time_t t) {
    struct tm epoch_tm = { .tm_year = 70, .tm_mday = 1 };
    time_t epoch_t = my_timegm(&epoch_tm);

    return (long) difftime(t, epoch_t);
}

time_t from_timestamp(tstamp_t ts) {
    fputs("Error: function from_timestamp is not implemented!", stderr);
    exit(EXIT_FAILURE);

#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnreachableCode"
    // NOTE: will never reach this return
    return time(NULL);
#pragma clang diagnostic pop
}
