#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "time_utils/time_utils.h"
#include "entry/entry.h"

int main(void) {
    puts("Hello, World!");

    time_t t = time(NULL);

    tstamp_t ts = to_timestamp(t);

    char *name = "Test lolol";
    size_t len = strlen(name);

    entry_t e = malloc(sizeof(*e) + sizeof(char) * (len + 1));

    e->timestamp = ts;
    e->cents = (long) (1936.27 * 100.0);

//    time_t t2 = from_timestamp(ts);

    strncpy(e->name, name, len);

    printf("%s: %.2LF\n", e->name, (((long double) e->cents) / 100.0));

    free(e);

    return 0;
}
