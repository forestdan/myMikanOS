#pragma once

#include <cstddef>

const int kTokeTimerValue = 46;

class Toke {
    public:
        Toke();
        ~Toke() = default;
        int getSecond();
        void secondPlusOne();
    private:
        int second_ = 0;
};