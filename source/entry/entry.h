//
// Created by zorgatone on 20/10/2023.
//

#ifndef EXPENSES_ENTRY_H
#define EXPENSES_ENTRY_H

#include <time.h>

typedef struct {
    long timestamp;
    unsigned long cents;

    // Dynamically allocated at the end of the struct
    char name[];
} *entry_t;

#endif //EXPENSES_ENTRY_H
