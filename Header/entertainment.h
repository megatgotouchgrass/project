#ifndef ENTERTAINMENT_H
#define ENTERTAINMENT_H
#include "init.h"
#include "authentication.h"
#include <chrono>
#include <fstream>
#include <string>
#include <token.h>
#include "timeprovider.h"

class Entertainment : public Init
{
protected:
    int capacity;
    int waitingTime;

public:
    Entertainment(){};
    Token token;        // composition
    TimeProvider *time; // aggregation
    int getCapacityFromCSV(const string &filename, const string &rideName);
    void mainMenu(Authentication &auth);
    virtual void bookEntertainment(int choice, Authentication &auth); // polymorphism (overriden method)

    int getCapacity() { return capacity; };
    int getTime() { return waitingTime; };
    void updateCapacity(int bookedSeats)
    {
        capacity -= bookedSeats;
    }
    void updateCapacity(const string &rowToUpdate, int newCapacity);
    void showBookings(Authentication &auth);
};

class BumperCars : public Entertainment
{
public:
    BumperCars();
    void bookEntertainment(int choice, Authentication &auth); // polymorphism (overriden method)
};

class Carousel : public Entertainment
{
public:
    Carousel();

    void bookEntertainment(int choice, Authentication &auth); // polymorphism (overriden method)
};

class RollerCoaster : public Entertainment
{
public:
    RollerCoaster();

    void bookEntertainment(int choice, Authentication &auth); // polymorphism (overriden method)
};

#endif