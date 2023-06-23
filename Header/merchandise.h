#ifndef MERCHANDISE_H
#define MERCHANDISE_H
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

class Merchandise : public Init
{
protected:
    vector<string> merchItems;
    vector<float> merchPrices;
    float totalMerchPrice;

public:
    Merchandise(){};
    Token token;
    void mainMenu();
    const vector<string> &getMerchItems() const;
    const vector<float> &getMerchPrices() const;
    void receipt(vector<string> selectedFoodItems);
    float calculateTotalPrice(vector<string> selectedMerchItems);
    ~Merchandise(){};
};

class GalacticBootcamp : public Merchandise
{
private:
public:
    GalacticBootcamp();
    void buyMerchandise();
};

class ParkEmporium : public Merchandise
{
private:
public:
    ParkEmporium();
    void buyMerchandise();
};

class RealmOfWonders : public Merchandise
{
private:
public:
    RealmOfWonders();
    void buyMerchandise();
};

#endif