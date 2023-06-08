#ifndef ENTERTAINMENT_H
#define ENTERTAINMENT_H
#include "init.h"
#include <chrono>

class Entertainment : public Init
{
private:
    int capacity;
    int waitingTime;

public:
    Entertainment(){};
    Entertainment(int cap, int wait);

    void mainMenu();
    virtual void bookEntertainment(); // polymorphism (overriden method)
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

    void bookEntertainment(); // polymorphism (redefined method)
};

class Carousel : public Entertainment
{
public:
    Carousel() : Entertainment(40, 4) {}

    void bookEntertainment(); // polymorphism (redefined method)
};

class RollerCoaster : public Entertainment
{
public:
    RollerCoaster() : Entertainment(20, 3) {}

    void bookEntertainment(); // polymorphism (redefined method)
};

#endif