#ifndef RESTAURANT_H
#define RESTAURANT_H
#include "init.h"
#include "authentication.h"
#include "string"
#include <fstream>
#include <sstream>
#include <vector>
#include <random>
#include <iomanip>
#include <ctime>
#include <algorithm>
#include "token.h"

class Restaurant : public Init
{
protected:
    vector<string> foodItems;
    vector<float> foodPrices;
    vector<string> beverageItems;
    vector<float> beveragePrices;
    float totalFoodPrice;
    float totalBeveragePrice;

public:
    Restaurant(){};
    Token token;
    void mainMenu();
    const vector<string> &getFoodItems() const;
    const vector<string> &getBeverageItems() const;
    const vector<float> &getFoodPrices() const;
    const vector<float> &getBeveragePrices() const;
    string generateUniqueToken();
    void receipt(vector<string> selectedFoodItems, vector<string> selectedBeverageItems);
    float calculateTotalPrice(vector<string> selectedFoodItems, vector<string> selectedBeverageItems);
    ~Restaurant(){};
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