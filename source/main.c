#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "time_utils/time_utils.h"
#include "timestamp/timestamp.h"
#include "entry/entry.h"

#define MAX_LINE 30
#define MAX_DATE_STR 120

int scan_tstamp(tstamp_t *timestamp);

int main(void) {
    puts("Hello, World!");

    tstamp_t ts;

    if (scan_tstamp(&ts)) {
        fputs("Error while getting date from standard input!\n", stderr);
        return EXIT_FAILURE;
    }

    char *name = "Test lolol";
    size_t len = strlen(name);

    entry_t e = malloc(sizeof(*e) + sizeof(char) * (len + 1));

    e->timestamp = ts;
    e->cents = (long) (1936.27 * 100.0);

    time_t n = time(NULL);
    struct tm n0 = *gmtime(&n);
    n = my_timegm(&n0);
    tstamp_t now = from_timestamp(n);

    strncpy(e->name, name, len);

    printf("%s: %.2F\n", e->name, (((double) e->cents) / 100.0));

    time_t t = from_timestamp(e->timestamp);
    struct tm t0 = *gmtime(&t);
    char date_string[MAX_DATE_STR];

    if (!strftime(date_string, sizeof(date_string), "%Y/%m/%d %H:%M", &t0)) {
        fputs("Error while trying to print time!\n", stderr);
        return EXIT_FAILURE;
    }

    printf("Date: %s\n", date_string);

    free(e);

    return EXIT_SUCCESS;
}

int scan_tstamp(tstamp_t *timestamp) {
    char line[MAX_LINE];

    fputs("Enter a UTC date/time\nYYYY/MM/DD HH:MM ", stdout);

    if (fgets(line, MAX_LINE, stdin) == NULL) {
        return 1;
    }

    int year, month, day;
    int hours = 0, minutes = 0; // optional

    int res = sscanf(line, "%d/%d/%d %d:%d", &year, &month, &day, &hours, &minutes);
    if (res < 3) {
        return 2;
    }

    if (month < 1 || month > 12) {
        return 3;
    }

    if (day < 1 || day > 31) {
        return 4;
    }

    if (hours < 0 || hours > 23) {
        return 5;
    }

    if (minutes < 0 || minutes > 59) {
        return 6;
    }

    struct tm st = {
        .tm_year = year - 1900,
        .tm_mon = month - 1,
        .tm_mday = day,
        .tm_hour = hours,
        .tm_min = minutes
    };

    time_t t = my_timegm(&st);

    *timestamp = to_timestamp(t);

    return 0;
}
