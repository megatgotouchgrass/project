#include "timer.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

Timer::Timer(chrono::seconds duration) : duration_(duration) {}

void Timer::start()
{
    timerThread_ = thread([&]()
                          { this_thread::sleep_for(duration_); });

    displayThread_ = thread(&Timer::displayTimer, this, duration_);
}

void Timer::displayTimer(chrono::seconds remainingTime)
{
    while (remainingTime.count() > 0)
    {
        cout << "Time remaining: " << remainingTime.count() << " seconds" << endl;
        this_thread::sleep_for(chrono::seconds(1));
        remainingTime -= chrono::seconds(1);
    }
};
