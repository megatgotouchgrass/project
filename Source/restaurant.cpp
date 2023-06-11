
#include "restaurant.h"
#include <iostream>
using namespace std;

void Restaurant::mainMenu(Authentication &auth)
{
    greetings();
    int selection;

    cout << "Which restaurant would you like to go?" << endl
         << endl;
    cout << "(1) Bronco Bistro" << endl;
    cout << "(2) Eastern Spice" << endl;
    cout << "(3) La Fiesta Mexicana" << endl;

    cout << "  __                   ___                       ( )" << endl;
    cout << " |\"\"|  ___    _   __  |\"\"\"|  \\__                   \\`" << endl;
    cout << " |\"\"| |\"\"\"|  |\"| |\"\"| |\"\"\"| |\"\"|        _._ _" << endl;
    cout << " |\"\"| |\"\"\"|  |\"| |\"\"| |\"\"\"| |\"\"|       (__((_(" << endl;
    cout << " |\"\"| |\"\"\"|  |\"| |\"\"| |\"\"\"| |\"\"|      \\\\'-:--:-." << endl;
    cout << " \"\'\'\'\"\'\'\"\'\"\"\'\"\"\"\'\'\"\'\'\'\'\"\"\"\'\"\"\'\"\"\'~~~~~~'-----'~~~~  " << endl;

    bookRestaurant();
}

void Restaurant::bookRestaurant()
{
    Restaurant *restaurant = nullptr;
    int selection = 0;
    do
    {
        cout << "Insert your selection here: ";
        cin >> selection;

    } while (!(selection > 0 && selection < 4));

    switch (selection)
    {
    case 1:
        restaurant = new BroncoBistro;
        readRestaurantMenu("BroncoBistro", foodItems, foodPrices, beverageItems, beveragePrices);
        break;
    case 2:
        restaurant = new EasternSpice;
        readRestaurantMenu("EasternSpice", foodItems, foodPrices, beverageItems, beveragePrices);
        break;
    case 3:
        restaurant = new LaFiestaMexicana;
        readRestaurantMenu("LaFiestaMexicana", foodItems, foodPrices, beverageItems, beveragePrices);
        break;
    };

    restaurant->bookRestaurant();
}

void Restaurant::readRestaurantMenu(const string &restaurantName, vector<string> &foodItems, vector<float> &foodPrices, vector<string> &beverageItems, vector<float> &beveragePrices)
{
    ifstream file("restaurant.csv");
    if (!file)
    {
        cout << "Error opening file." << endl;
        return;
    }

    string line;
    bool foundRestaurant = false;
    bool foundFood = false;
    bool foundBeverage = false;

    while (getline(file, line))
    {
        if (line.find(restaurantName) != std::string::npos)
        {
            foundRestaurant = true;
        }
        else if (line.empty())
        {
            foundRestaurant = false;
        }
        else if (foundRestaurant)
        {
            // Assuming the format is "Item, Price"
            size_t commaPos = line.find(',');
            if (commaPos != std::string::npos)
            {
                std::string itemName = line.substr(0, commaPos);
                std::string itemPriceStr = line.substr(commaPos + 1);
                float itemPrice = std::stof(itemPriceStr);
                if (itemName.find("Food") != std::string::npos)
                {
                    foodItems.push_back(itemName);
                    foodPrices.push_back(itemPrice);
                }
                else if (itemName.find("Beverage") != std::string::npos)
                {
                    beverageItems.push_back(itemName);
                    beveragePrices.push_back(itemPrice);
                }
            }
        }
    }
}

void Restaurant::addFood(const string &foodName, int price)
{
    foodItems.push_back(foodName);
    foodPrices.push_back(price);
}

void Restaurant::addBeverage(const string &beverageName, int price)
{
    beverageItems.push_back(beverageName);
    beveragePrices.push_back(price);
}

BroncoBistro::BroncoBistro()
{
}
EasternSpice::EasternSpice()
{
}
LaFiestaMexicana::LaFiestaMexicana()
{
}

const vector<string> &Restaurant::getFoodItems() const
{
    return foodItems;
}

const vector<string> &Restaurant::getBeverageItems() const
{
    return beverageItems;
}

const vector<float> &Restaurant::getFoodPrices() const
{
    return foodPrices;
}

const vector<float> &Restaurant::getBeveragePrices() const
{
    return beveragePrices;
}

void BroncoBistro::bookRestaurant()
{
    cout << "Bronco Bistro Menu:" << endl;

    // Access food items and their prices from the base class
    foodItems = getFoodItems();
    foodPrices = getFoodPrices();
    beverageItems = getBeverageItems();
    beveragePrices = getBeveragePrices();

    // Display food items and their prices
    cout << "Food:" << endl;
    for (size_t i = 0; i < foodItems.size(); ++i)
    {
        cout << "- " << foodItems[i] << ": $" << foodPrices[i] << endl;
    }

    // Display beverage items and their prices
    cout << "Beverage:" << endl;
    for (size_t i = 0; i < beverageItems.size(); ++i)
    {
        cout << "- " << beverageItems[i] << ": $" << beveragePrices[i] << endl;
    }
}

// Repeat the same changes for the EasternSpice and LaFiestaMexicana classes

void EasternSpice::bookRestaurant()
{
    cout << "Eastern Spice Menu:" << endl;

    foodItems = getFoodItems();
    foodPrices = getFoodPrices();
    beverageItems = getBeverageItems();
    beveragePrices = getBeveragePrices();

    // Display food items and their prices
    cout << "Food:" << endl;
    for (size_t i = 0; i < foodItems.size(); ++i)
    {
        cout << "- " << foodItems[i] << ": $" << foodPrices[i] << endl;
    }

    // Display beverage items and their prices
    cout << "Beverage:" << endl;
    for (size_t i = 0; i < beverageItems.size(); ++i)
    {
        cout << "- " << beverageItems[i] << ": $" << beveragePrices[i] << endl;
    }
}

void LaFiestaMexicana::bookRestaurant()
{
    cout << "La Fiesta Mexicana Menu:" << endl;

    foodItems = getFoodItems();
    foodPrices = getFoodPrices();
    beverageItems = getBeverageItems();
    beveragePrices = getBeveragePrices();

    // Display food items and their prices
    cout << "Food:" << endl;
    for (size_t i = 0; i < foodItems.size(); ++i)
    {
        cout << "- " << foodItems[i] << ": $" << foodPrices[i] << endl;
    }

    // Display beverage items and their prices
    cout << "Beverage:" << endl;
    for (size_t i = 0; i < beverageItems.size(); ++i)
    {
        cout << "- " << beverageItems[i] << ": $" << beveragePrices[i] << endl;
    }
}
