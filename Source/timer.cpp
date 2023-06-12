#include "timer.h"

string TimeProvider::getCurrentTime()
{
    chrono::system_clock::time_point now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);
    string timeString = ctime(&currentTime);
    // Remove the newline character from the timeString
    if (!timeString.empty() && timeString[timeString.length() - 1] == '\n')
    {
        timeString.erase(timeString.length() - 1);
    }
    return timeString;
}