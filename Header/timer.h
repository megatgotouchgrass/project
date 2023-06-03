#ifndef TIMER_H
#define TIMER_H
#include <chrono>
#include <thread>

using namespace std;

class Timer
{
private:
    chrono::seconds duration_;
    thread timerThread_;
    thread displayThread_;

public:
    Timer(chrono::seconds duration);
    void start();
    void displayTimer(chrono::seconds remainingTime);
};

#endif