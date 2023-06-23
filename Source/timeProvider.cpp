#include "timeprovider.h"

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

string TimeProvider::getWaitingTime(const string choice)
{
    chrono::system_clock::time_point now = chrono::system_clock::now();
    chrono::system_clock::time_point waitingTime;

    if (choice == "RollerCoaster")
    {

        chrono::minutes minutesToAdd(5);
        waitingTime = now + minutesToAdd;
    }
    else if (choice == "BumperCars")
    {

        chrono::minutes minutesToAdd(10);
        waitingTime = now + minutesToAdd;
    }
    else if (choice == "Carousel")
    {

        chrono::minutes minutesToAdd(10);
        waitingTime = now + minutesToAdd;
    }

    auto duration = waitingTime - now;
    auto minutes = chrono::duration_cast<chrono::minutes>(duration);
    auto seconds = chrono::duration_cast<chrono::seconds>(duration) - minutes;

    string minuteString = to_string(minutes.count());
    string secondsString = to_string(seconds.count());

    return minuteString + " minutes and " + secondsString + " seconds";
}