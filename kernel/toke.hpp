#pragma once

#include <cstddef>

const int kTokeTimerValue = 46;

class Toke {
    public:
        Toke();
        Toke(int hour, int minute, int second);
        ~Toke() = default;
        void secondPlusOne();
        void getTime(int* hour, int* minute, int* second);
    private:
        int hour_ = 0;
        int minutes_ = 0;
        int second_ = 0;
};