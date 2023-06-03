#ifndef ATTRACTION_H
#define ATTRACTION_H
#include "timer.h"
#include <chrono>

class Attraction
{
    Timer timer;

public:
    Attraction() : timer(chrono::seconds(10)){};

    void bookAttraction();
};

#endif