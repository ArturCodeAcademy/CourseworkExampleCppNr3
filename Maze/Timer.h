#pragma once

#include <time.h>

class Timer
{
private:
    long long nextStop;
    long long pause;

public:
    Timer(long long pause) : pause(pause), nextStop(pause + clock()) {}

    inline bool IsPausePassed()
    {
        if (nextStop <= clock())
        {
            nextStop += pause;
            return true;
        }
        return false;
    }
};