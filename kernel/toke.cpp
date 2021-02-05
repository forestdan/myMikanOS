#include "toke.hpp"
#include "console.hpp"
#include "logger.hpp"

Toke::Toke(){};

Toke::Toke(int hour, int minute, int second) {
    hour_ = hour;
    minutes_ = minute;
    second_ = second;
}

void Toke::getTime(int* hour, int* minute, int* second) {
    *hour = hour_;
    *minute = minutes_;
    *second = second_;
}

void Toke::secondPlusOne() {
    ++second_;
    if (second_ > 59) {
        second_ = 0;
        ++minutes_;
        if (minutes_ > 59) {
            minutes_ = 0;
            ++hour_;
            if (hour_ > 23) {
                hour_ = 0;
            }
        }
    }
}