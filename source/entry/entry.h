//
// Created by zorgatone on 20/10/2023.
//

#ifndef EXPENSES_ENTRY_H
#define EXPENSES_ENTRY_H

#include <time.h>

#include "time_utils/time_utils.h"

typedef struct {
    tstamp_t timestamp;
    long cents;

    // Dynamically allocated at the end of the struct
    char name[];
} *entry_t;

#endif //EXPENSES_ENTRY_H
