#ifndef TIMEPROVIDER_H
#define TIMEPROVIDER_H
#include <chrono>
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class TimeProvider
{
public:
    TimeProvider(){};
    string getCurrentTime();
    string getWaitingTime(const string choice);
    ~TimeProvider(){};
};

#endif