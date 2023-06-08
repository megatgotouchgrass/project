#ifndef RESTAURANT_H
#define RESTAURANT_H
#include "init.h"

class Restaurant : public Init
{
private:
    int beverage;
    int food;

public:
    void mainMenu();
    void bookRestaurant();
};

class Bronco : public Restaurant
{
private:
    int priceFood;
    int price;

public:
    Bronco() {}
};

#endif