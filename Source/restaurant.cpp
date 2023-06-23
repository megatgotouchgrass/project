#include "restaurant.h"
#include <iostream>
using namespace std;

void Restaurant::receipt(vector<string> selectedFoodItems, vector<string> selectedBeverageItems)
{
    // Generate a unique token
    string idToken = token.generateUniqueToken();

    // Calculate the total price
    float totalPrice = calculateTotalPrice(selectedFoodItems, selectedBeverageItems);

    // Display the receipt
    cout << endl;
    cout << setw(36 + 42) << "---------------- Receipt ----------------" << endl;
    cout << setw(36 + 11) << "ID Token: " << idToken << endl;
    cout << setw(36 + 15) << "Total Price: $" << fixed << setprecision(2) << totalPrice << endl;
    cout << setw(36 + 41) << "----------------------------------------" << endl;

    // Store the receipt information in a file
    ofstream file("receiptRestaurant.csv", ios::app);
    try
    {
        if (file.is_open())
        {
            file << "ID Token: " << idToken << endl;
            file << "Total Price: $" << fixed << setprecision(2) << totalPrice << endl;
            file << "----------------------------------------" << endl;
            file.close();
        }
        else
        {
            throw e;
        }
    }
    catch (ErrorHandler e)
    {
        e.fileError();
    }
}

float Restaurant::calculateTotalPrice(vector<string> selectedFoodItems, vector<string> selectedBeverageItems)
{
    for (int i = 0; i < selectedFoodItems.size(); ++i)
    {
        int foodIndex = find(foodItems.begin(), foodItems.end(), selectedFoodItems[i]) - foodItems.begin();
        if (foodIndex >= 0 && foodIndex < foodPrices.size())
        {
            totalFoodPrice += foodPrices[foodIndex];
        }
    }

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

void Restaurant::mainMenu()
{
    greetings();
    int selection;

    cout << setw(75) << "Which restaurant would you like to go?" << endl;
    cout << setw(45 + 18) << "(1) Bronco Bistro" << endl;
    cout << setw(45 + 18) << "(2) Eastern Spice" << endl;
    cout << setw(45 + 23) << "(3) La Fiesta Mexicana" << endl;

    cout << setw(31 + 53) << "  __                   ___                       ( )" << endl;
    cout << setw(31 + 54) << " |\"\"|  ___    _   __  |\"\"\"|  \\__                   \\`" << endl;
    cout << setw(31 + 46) << " |\"\"| |\"\"\"|  |\"| |\"\"| |\"\"\"| |\"\"|        _._ _" << endl;
    cout << setw(31 + 47) << " |\"\"| |\"\"\"|  |\"| |\"\"| |\"\"\"| |\"\"|       (__((_(" << endl;
    cout << setw(31 + 49) << " |\"\"| |\"\"\"|  |\"| |\"\"| |\"\"\"| |\"\"|      \\\\'-:--:-." << endl;
    cout << setw(31 + 53) << " \"\'\'\'\"\'\'\"\'\"\"\'\"\"\"\'\'\"\'\'\'\'\"\"\"\'\"\"\'\"\"\'~~~~~~'-----'~~~~  " << endl;

    cout << endl
         << setw(64) << "Insert selection: ";
    cin >>
        selection;

    try
    {
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
            throw e;
        }
    }
    catch (ErrorHandler e)
    {
        e.invalidInput();
    }
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
    cout << setw(40 + 25) << "Booking Bronco Bistro..." << endl;

    int capacity;
    cout << setw(40 + 31) << "Booking for how many people?: ";
    cin >> capacity;

    cout << endl
         << setw(40 + 22)
         << "Available Food Items:" << endl;
    for (int i = 0; i < foodItems.size(); i++)
    {
        cout << setw(42) << "(" << i + 1 << ") " << foodItems[i] << " - $" << foodPrices[i] << endl;
    }

    cout << endl;
    vector<string> selectedFoodItems;
    int foodChoice;

    do
    {
        cout << setw(40 + 41) << "Select a food item (enter 0 to finish): ";
        cin >> foodChoice;
        try
        {
            if (foodChoice > 0 && foodChoice <= foodItems.size())
            {
                selectedFoodItems.push_back(foodItems[foodChoice - 1]);
            }
            else if (foodChoice < 0)
            {
                throw e;
            }
        }
        catch (ErrorHandler e)
        {
            e.invalidInput();
        };
    } while (foodChoice != 0);

    cout << endl;
    cout << setw(40 + 26) << "Available Beverage Items:" << endl;
    for (int i = 0; i < beverageItems.size(); i++)
    {
        cout << setw(42) << "(" << i + 1 << ") " << beverageItems[i] << " - $" << beveragePrices[i] << endl;
    }

    vector<string> selectedBeverageItems;
    int beverageChoice;
    cout << endl;

    do
    {
        cout << setw(40 + 45) << "Select a beverage item (enter 0 to finish): ";
        cin >> beverageChoice;
        try
        {
            if (beverageChoice > 0 && beverageChoice <= beverageItems.size())
            {
                selectedBeverageItems.push_back(beverageItems[beverageChoice - 1]);
            }
            else if (beverageChoice < 0)
            {
                throw e;
            }
        }
        catch (ErrorHandler e)
        {
            e.invalidInput();
        }
    } while (beverageChoice != 0);

    // Perform the booking based on the selected options
    greetings();
    cout << setw(40 + 23) << "Booking confirmed for " << capacity << " people." << endl
         << endl;
    cout << setw(40 + 21) << "Food items selected:" << endl;
    for (const auto &food : selectedFoodItems)
    {
        cout << setw(47) << food << endl;
    }
    cout << endl;

    cout << setw(40 + 25) << "Beverage items selected:" << endl;
    for (const auto &beverage : selectedBeverageItems)
    {
        cout << setw(47) << beverage << endl;
    }

    receipt(selectedFoodItems, selectedBeverageItems);
}

void EasternSpice::bookRestaurant()
{
    greetings();
    cout << setw(40 + 25) << "Booking Eastern Spice..." << endl;

    int capacity;
    cout << setw(40 + 31) << "Booking for how many people?: ";
    cin >> capacity;

    cout << endl
         << setw(40 + 22)
         << "Available Food Items:" << endl;
    for (int i = 0; i < foodItems.size(); i++)
    {
        cout << setw(42) << "(" << i + 1 << ") " << foodItems[i] << " - $" << foodPrices[i] << endl;
    }

    cout << endl;
    vector<string> selectedFoodItems;
    int foodChoice;

    do
    {
        cout << setw(40 + 41) << "Select a food item (enter 0 to finish): ";
        cin >> foodChoice;
        try
        {
            if (foodChoice > 0 && foodChoice <= foodItems.size())
            {
                selectedFoodItems.push_back(foodItems[foodChoice - 1]);
            }
            else if (foodChoice < 0)
            {
                throw e;
            }
        }
        catch (ErrorHandler e)
        {
            e.invalidInput();
        };
    } while (foodChoice != 0);

    cout << endl;
    cout << setw(40 + 26) << "Available Beverage Items:" << endl;
    for (int i = 0; i < beverageItems.size(); i++)
    {
        cout << setw(42) << "(" << i + 1 << ") " << beverageItems[i] << " - $" << beveragePrices[i] << endl;
    }

    vector<string> selectedBeverageItems;
    int beverageChoice;
    cout << endl;

    do
    {
        cout << setw(40 + 45) << "Select a beverage item (enter 0 to finish): ";
        cin >> beverageChoice;
        try
        {
            if (beverageChoice > 0 && beverageChoice <= beverageItems.size())
            {
                selectedBeverageItems.push_back(beverageItems[beverageChoice - 1]);
            }
            else if (beverageChoice < 0)
            {
                throw e;
            }
        }
        catch (ErrorHandler e)
        {
            e.invalidInput();
        }
    } while (beverageChoice != 0);

    // Perform the booking based on the selected options
    greetings();
    cout << setw(40 + 23) << "Booking confirmed for " << capacity << " people." << endl
         << endl;
    cout << setw(40 + 21) << "Food items selected:" << endl;
    for (const auto &food : selectedFoodItems)
    {
        cout << setw(47) << food << endl;
    }
    cout << endl;

    cout << setw(40 + 25) << "Beverage items selected:" << endl;
    for (const auto &beverage : selectedBeverageItems)
    {
        cout << setw(47) << beverage << endl;
    }

    receipt(selectedFoodItems, selectedBeverageItems);
}

void LaFiestaMexicana::bookRestaurant()
{
    greetings();
    cout << setw(40 + 25) << "Booking La Fiesta Mexicana..." << endl;
    int capacity;
    cout << setw(40 + 31) << "Booking for how many people?: ";
    cin >> capacity;

    cout << endl
         << setw(40 + 22)
         << "Available Food Items:" << endl;
    for (int i = 0; i < foodItems.size(); i++)
    {
        cout << setw(42) << "(" << i + 1 << ") " << foodItems[i] << " - $" << foodPrices[i] << endl;
    }

    cout << endl;
    vector<string> selectedFoodItems;
    int foodChoice;
    do
    {
        cout << setw(40 + 41) << "Select a food item (enter 0 to finish): ";
        cin >> foodChoice;
        try
        {
            if (foodChoice > 0 && foodChoice <= foodItems.size())
            {
                selectedFoodItems.push_back(foodItems[foodChoice - 1]);
            }
            else if (foodChoice < 0)
            {
                throw e;
            }
        }
        catch (ErrorHandler e)
        {
            e.invalidInput();
        };
    } while (foodChoice != 0);

    cout << endl;
    cout << setw(40 + 26) << "Available Beverage Items:" << endl;
    for (int i = 0; i < beverageItems.size(); i++)
    {
        cout << setw(42) << "(" << i + 1 << ") " << beverageItems[i] << " - $" << beveragePrices[i] << endl;
    }

    vector<string> selectedBeverageItems;
    int beverageChoice;
    cout << endl;

    do
    {
        cout << setw(40 + 45) << "Select a beverage item (enter 0 to finish): ";
        cin >> beverageChoice;
        try
        {
            if (beverageChoice > 0 && beverageChoice <= beverageItems.size())
            {
                selectedBeverageItems.push_back(beverageItems[beverageChoice - 1]);
            }
            else if (beverageChoice < 0)
            {
                throw e;
            }
        }
        catch (ErrorHandler e)
        {
            e.invalidInput();
        }
    } while (beverageChoice != 0);

    // Perform the booking based on the selected options
    greetings();
    cout << setw(40 + 23) << "Booking confirmed for " << capacity << " people." << endl
         << endl;
    cout << setw(40 + 21) << "Food items selected:" << endl;
    for (const auto &food : selectedFoodItems)
    {
        cout << setw(47) << food << endl;
    }
    cout << endl;

    cout << setw(40 + 25) << "Beverage items selected:" << endl;
    for (const auto &beverage : selectedBeverageItems)
    {
        cout << setw(47) << beverage << endl;
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
