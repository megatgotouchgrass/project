#ifndef TIMER_H
#define TIMER_H
#include <chrono>
#include <iostream>

using namespace std;

class TimeProvider
{
public:
    TimeProvider(){};
    string getCurrentTime();
    ~TimeProvider(){};
};

#endif