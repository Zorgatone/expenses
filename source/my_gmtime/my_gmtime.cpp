//
// Created by zorgatone on 22/10/2023.
//

#include <chrono>

#include "my_gmtime.h"

#ifdef __cplusplus
extern "C" {
#endif

// https://stackoverflow.com/a/75714048/1255826
std::time_t my_gmtime(std::tm const *t) {
    using namespace std::chrono;
    return system_clock::to_time_t(
            sys_days{year{t->tm_year+1900}/(t->tm_mon+1)/t->tm_mday} +
            hours{t->tm_hour} + minutes{t->tm_min} + seconds{t->tm_sec});
}

#ifdef __cplusplus
}
#endif