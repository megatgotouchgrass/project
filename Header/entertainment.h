#ifndef ENTERTAINMENT_H
#define ENTERTAINMENT_H
#include "timer.h"
#include "init.h"
#include <chrono>

class Entertainment : public Init
{
private:
    int capacity;
    int waitingTime;

public:
    Entertainment() : timer(chrono::seconds(0)){};
    Entertainment(int cap, int wait);

    Timer timer;

    void mainMenu();
    void bookAttraction();
    void displayDetails();

    int getCapacity() { return capacity; };
    int getTime() { return waitingTime; };
    void updateCapacity(int bookedSeats)
    {
        capacity -= bookedSeats;
    }
};

class BumperCars : public Entertainment
{
public:
    BumperCars() : Entertainment(2, 5)
    {
    }
};

class Carousel : public Entertainment
{
public:
    Carousel() : Entertainment(40, 4) {}
};

class RollerCoaster : public Entertainment
{
public:
    RollerCoaster() : Entertainment(20, 3) {}
};

#endif