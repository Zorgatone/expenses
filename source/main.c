#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_gmtime/my_gmtime.h"
#include "entry/entry.h"

long to_timestamp(time_t t);

int main(void) {
    puts("Hello, World!");

    time_t t = time(NULL);

    long ts = to_timestamp(t);

    char *name = "Test lolol";
    size_t len = strlen(name);

    entry_t e = malloc(sizeof(*e) + sizeof(char) * (len + 1));

    e->timestamp = ts;
    e->cents = (unsigned long) (1936.27 * 100.0);

    strncpy(e->name, name, len);

    printf("%s: %.2LF\n", e->name, (((long double) e->cents) / 100.0));

    free(e);

    return 0;
}

long to_timestamp(time_t t) {
    struct tm epoch_tm = { .tm_year = 70, .tm_mday = 1 };
    time_t epoch_t = my_gmtime(&epoch_tm);

    return (long) difftime(t, epoch_t);
}
