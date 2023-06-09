#ifndef ENTERTAINMENT_H
#define ENTERTAINMENT_H
#include "init.h"
#include "authentication.h"
#include <chrono>
#include <fstream>

class Entertainment : public Init
{
protected:
    int capacity;
    int waitingTime;

public:
    Authentication auth;
    Entertainment(){};
    Entertainment(int cap, int wait);

    void mainMenu();
    virtual void bookEntertainment(int choice); // polymorphism (overriden method)
    void displayDetails();

    int getCapacity() { return capacity; };
    int getTime() { return waitingTime; };
    void updateCapacity(int bookedSeats)
    {
        capacity -= bookedSeats;
    }
    void updateWaitingCapacity(const string &entertainmentType, int newCapacity, int newWaitingTime);
};

class BumperCars : public Entertainment
{
public:
    BumperCars() : Entertainment(2, 5) {}
    void bookEntertainment(int choice); // polymorphism (redefined method)
};

class Carousel : public Entertainment
{
public:
    Carousel() : Entertainment(40, 4) {}

    void bookEntertainment(int choice); // polymorphism (redefined method)
};

class RollerCoaster : public Entertainment
{
public:
    RollerCoaster() : Entertainment(20, 3) {}

    void bookEntertainment(int choice); // polymorphism (redefined method)
};

#endif