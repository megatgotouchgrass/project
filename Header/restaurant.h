#ifndef RESTAURANT_H
#define RESTAURANT_H
#include "init.h"
#include "authentication.h"
#include "string"
#include <fstream>
#include <sstream>
#include <vector>

class Restaurant : public Init
{
protected:
    vector<string> foodItems;
    vector<float> foodPrices;
    vector<string> beverageItems;
    vector<float> beveragePrices;

public:
    void mainMenu(Authentication &auth);
    virtual void bookRestaurant();
    void readRestaurantMenu(const string &restaurantName, vector<string> &foodItems, vector<float> &foodPrices, vector<string> &beverageItems, vector<float> &beveragePrices);
    void addFood(const string &foodName, int price);
    void addBeverage(const string &beverageName, int price);
    const vector<string> &getFoodItems() const;
    const vector<string> &getBeverageItems() const;
    const vector<float> &getFoodPrices() const;
    const vector<float> &getBeveragePrices() const;
};

class BroncoBistro : public Restaurant
{
private:
public:
    BroncoBistro();
    void bookRestaurant();
};

class EasternSpice : public Restaurant
{
private:
public:
    EasternSpice();
    void bookRestaurant();
};

class LaFiestaMexicana : public Restaurant
{
private:
public:
    LaFiestaMexicana();
    void bookRestaurant();
};

#endif