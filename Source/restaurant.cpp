#include "restaurant.h"
#include <iostream>
using namespace std;

void Restaurant::receipt(vector<string> selectedFoodItems, vector<string> selectedBeverageItems)
{
    // Generate a unique token
    string idToken = generateUniqueToken();

    // Calculate the total price
    float totalPrice = calculateTotalPrice(selectedFoodItems, selectedBeverageItems);

    // Display the receipt
    cout << "---------------- Receipt ----------------" << endl;
    cout << "ID Token: " << idToken << endl;
    cout << "Total Price: $" << fixed << setprecision(2) << totalPrice << endl;
    cout << "----------------------------------------" << endl;

    // Store the receipt information in a file
    ofstream file("receipt.csv", ios::app);
    if (file.is_open())
    {
        file << "ID Token: " << idToken << endl;
        file << "Total Price: $" << fixed << setprecision(2) << totalPrice << endl;
        file << "----------------------------------------" << endl;
        file.close();
    }
    else
    {
        cout << "Error: Unable to open the file." << endl;
    }
}

float Restaurant::calculateTotalPrice(vector<string> selectedFoodItems, vector<string> selectedBeverageItems)
{
    // Calculate the total price based on the selected food and beverage items
    // Use the vectors foodItems, foodPrices, beverageItems, beveragePrices

    // For example:
    for (int i = 0; i < selectedFoodItems.size(); ++i)
    {
        int foodIndex = find(foodItems.begin(), foodItems.end(), selectedFoodItems[i]) - foodItems.begin();
        if (foodIndex >= 0 && foodIndex < foodPrices.size())
        {
            totalFoodPrice += foodPrices[foodIndex];
        }
    }

    float totalBeveragePrice = 0.0;
    for (int i = 0; i < selectedBeverageItems.size(); ++i)
    {
        int beverageIndex = find(beverageItems.begin(), beverageItems.end(), selectedBeverageItems[i]) - beverageItems.begin();
        if (beverageIndex >= 0 && beverageIndex < beveragePrices.size())
        {
            totalBeveragePrice += beveragePrices[beverageIndex];
        }
    }

    return totalFoodPrice + totalBeveragePrice;
}

string Restaurant::generateUniqueToken()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(100000, 999999);
    int randomID = distribution(gen);
    ostringstream oss;
    oss << setfill('0') << setw(6) << randomID;
    return oss.str();
}

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

    cout << endl
         << "Insert selection: ";
    cin >>
        selection;

    switch (selection)
    {
    case 1:
    {
        BroncoBistro bistro;
        bistro.bookRestaurant();
        break;
    }
    case 2:
    {
        EasternSpice spice;
        spice.bookRestaurant();
        break;
    }
    case 3:
    {
        LaFiestaMexicana fiesta;
        fiesta.bookRestaurant();
        break;
    }
    default:
        cout << "Invalid selection!" << endl;
    }
}

void Restaurant::bookRestaurant()
{
    cout << "Booking restaurant..." << endl;
}

BroncoBistro::BroncoBistro()
{
    // Initialize the menu items for Bronco Bistro
    foodItems = {"Burger", "Fries", "Salad"};
    foodPrices = {10.99, 4.99, 7.99};
    beverageItems = {"Soda", "Water", "Iced Tea"};
    beveragePrices = {1.99, 1.49, 2.49};
}

EasternSpice::EasternSpice()
{
    // Initialize the menu items for Eastern Spice
    foodItems = {"Chicken Curry", "Vegetable Biryani", "Naan"};
    foodPrices = {12.99, 9.99, 2.99};
    beverageItems = {"Mango Lassi", "Chai", "Soda"};
    beveragePrices = {3.99, 2.99, 1.99};
}

LaFiestaMexicana::LaFiestaMexicana()
{
    // Initialize the menu items for La Fiesta Mexicana
    foodItems = {"Taco", "Burrito", "Enchilada"};
    foodPrices = {8.99, 10.99, 9.99};
    beverageItems = {"Margarita", "Tequila Sunrise", "Soda"};
    beveragePrices = {6.99, 7.99, 1.99};
}

void BroncoBistro::bookRestaurant()
{
    greetings();
    cout << "Booking Bronco Bistro..." << endl;

    int capacity;
    cout << "Booking for how many people?: ";
    cin >> capacity;

    cout << endl
         << "Available Food Items:" << endl;
    for (int i = 0; i < foodItems.size(); i++)
    {
        cout << "(" << i + 1 << ") " << foodItems[i] << " - $" << foodPrices[i] << endl;
    }

    cout << endl;
    vector<string> selectedFoodItems;
    int foodChoice;
    do
    {
        cout << "Select a food item (enter 0 to finish): ";
        cin >> foodChoice;
        if (foodChoice > 0 && foodChoice <= foodItems.size())
        {
            selectedFoodItems.push_back(foodItems[foodChoice - 1]);
        }
    } while (foodChoice != 0);
    cout << endl;
    cout << "Available Beverage Items:" << endl;
    for (int i = 0; i < beverageItems.size(); i++)
    {
        cout << "(" << i + 1 << ") " << beverageItems[i] << " - $" << beveragePrices[i] << endl;
    }

    vector<string> selectedBeverageItems;
    int beverageChoice;
    cout << endl;
    do
    {
        cout << "Select a beverage item (enter 0 to finish): ";
        cin >> beverageChoice;
        if (beverageChoice > 0 && beverageChoice <= beverageItems.size())
        {
            selectedBeverageItems.push_back(beverageItems[beverageChoice - 1]);
        }
    } while (beverageChoice != 0);

    // Perform the booking based on the selected options
    greetings();
    cout << "Booking confirmed for " << capacity << " people." << endl
         << endl;
    cout << "Food items selected:" << endl;
    for (const auto &food : selectedFoodItems)
    {
        cout << food << endl;
    }
    cout << endl;

    cout << "Beverage items selected:" << endl;
    for (const auto &beverage : selectedBeverageItems)
    {
        cout << beverage << endl;
    }

    receipt(selectedFoodItems, selectedBeverageItems);
}

void EasternSpice::bookRestaurant()
{
    greetings();
    cout << "Booking Eastern Spice..." << endl;

    int capacity;
    cout << "Booking for how many people?: ";
    cin >> capacity;

    cout << endl
         << "Available Food Items:" << endl;
    for (int i = 0; i < foodItems.size(); i++)
    {
        cout << "(" << i + 1 << ") " << foodItems[i] << " - $" << foodPrices[i] << endl;
    }
    cout << endl;

    vector<string> selectedFoodItems;
    int foodChoice;
    do
    {
        cout << "Select a food item (enter 0 to finish): ";
        cin >> foodChoice;
        if (foodChoice > 0 && foodChoice <= foodItems.size())
        {
            selectedFoodItems.push_back(foodItems[foodChoice - 1]);
        }
    } while (foodChoice != 0);
    cout << endl;
    cout << "Available Beverage Items:" << endl;
    for (int i = 0; i < beverageItems.size(); i++)
    {
        cout << "(" << i + 1 << ") " << beverageItems[i] << " - $" << beveragePrices[i] << endl;
    }

    vector<string> selectedBeverageItems;
    int beverageChoice;
    cout << endl;
    do
    {
        cout << "Select a beverage item (enter 0 to finish): ";
        cin >> beverageChoice;
        if (beverageChoice > 0 && beverageChoice <= beverageItems.size())
        {
            selectedBeverageItems.push_back(beverageItems[beverageChoice - 1]);
        }
    } while (beverageChoice != 0);

    // Perform the booking based on the selected options
    greetings();
    cout << "Booking confirmed for " << capacity << " people." << endl
         << endl;
    cout << "Food items selected:" << endl;
    for (const auto &food : selectedFoodItems)
    {
        cout << food << endl;
    }
    cout << endl;

    cout << "Beverage items selected:" << endl;
    for (const auto &beverage : selectedBeverageItems)
    {
        cout << beverage << endl;
    }
    receipt(selectedFoodItems, selectedBeverageItems);
}

void LaFiestaMexicana::bookRestaurant()
{
    greetings();
    cout << "Booking La Fiesta Mexicana..." << endl;

    int capacity;
    cout << endl
         << "Booking for how many people?: ";
    cin >> capacity;

    cout << "Available Food Items:" << endl;
    for (int i = 0; i < foodItems.size(); i++)
    {
        cout << "(" << i + 1 << ") " << foodItems[i] << " - $" << foodPrices[i] << endl;
    }

    cout << endl;
    vector<string> selectedFoodItems;
    int foodChoice;
    do
    {
        cout << "Select a food item (enter 0 to finish): ";
        cin >> foodChoice;
        if (foodChoice > 0 && foodChoice <= foodItems.size())
        {
            selectedFoodItems.push_back(foodItems[foodChoice - 1]);
        }
    } while (foodChoice != 0);

    cout << "Available Beverage Items:" << endl;
    for (int i = 0; i < beverageItems.size(); i++)
    {
        cout << "(" << i + 1 << ") " << beverageItems[i] << " - $" << beveragePrices[i] << endl;
    }

    vector<string> selectedBeverageItems;
    int beverageChoice;
    cout << endl;
    do
    {
        cout << "Select a beverage item (enter 0 to finish): ";
        cin >> beverageChoice;
        if (beverageChoice > 0 && beverageChoice <= beverageItems.size())
        {
            selectedBeverageItems.push_back(beverageItems[beverageChoice - 1]);
        }
    } while (beverageChoice != 0);

    // Perform the booking based on the selected options
    greetings();
    cout << "Booking confirmed for " << capacity << " people." << endl
         << endl;
    cout << "Food items selected:" << endl;
    for (const auto &food : selectedFoodItems)
    {
        cout << food << endl;
    }
    cout << endl;
    cout << "Beverage items selected:" << endl;
    for (const auto &beverage : selectedBeverageItems)
    {
        cout << beverage << endl;
    }
    receipt(selectedFoodItems, selectedBeverageItems);
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
