//
// Created by zorgatone on 22/10/2023.
//

#include <chrono>

#include "time_utils.h"

extern "C" {
    // https://stackoverflow.com/a/75714048/1255826
    std::time_t my_timegm(std::tm const *t) {
        using namespace std::chrono;
        return system_clock::to_time_t(
                sys_days{year{t->tm_year+1900}/(t->tm_mon+1)/t->tm_mday} +
                hours{t->tm_hour} + minutes{t->tm_min} + seconds{t->tm_sec});
    }

    std::time_t time_add(std::time_t t, long duration) {
        using namespace std::chrono;
        return system_clock::to_time_t(
            system_clock::from_time_t(t) + seconds(duration)
        );
    }
}
