
#include "restaurant.h"
#include <iostream>
using namespace std;

void Restaurant::mainMenu()
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
    int selection;
    do
    {
        cout << "Insert your selection here: ";
        cin >> selection;

    } while (!(selection > 0 && selection < 4));

    switch (selection)
    {
    case 1:
    {
        cout << "Welcome to Bronco Bistro!" << endl
             << endl;

        cout << "Do you want to order food? Press 'Y' for Yes, 'N' for No: ";
        char foodChoice;
        cin >> foodChoice;

        if (foodChoice == 'Y' || foodChoice == 'y')
        {
            cout << "What food would you like? Smoked Burger(0) or Italian Pizza(1): ";
            int foodType;
            cin >> foodType;

            if (foodType == 0)
            {
            }
            else if (foodType == 1)
            {
            }
        }
        break;
    }
    case 2:
        break;
    };
}

//     if (orderChoice == 'Y' || orderChoice == 'y')
//     {
//         cout << "Do you want to order a beverage? Press 'Y' for Yes, 'N' for No: ";
//         char beverageChoice;
//         cin >> beverageChoice;

//         if (beverageChoice == 'Y' || beverageChoice == 'y')
//         {
//             cout << "What beverage would you like? Coffee(0) or Smoothie(1): ";
//             int beverageType;
//             cin >> beverageType;

//             if (beverageType == 0)
//             {
//                 b1.setPrice(7);
//                 r1.setBeverage(1);
//             }
//             else if (beverageType == 1)
//             {
//                 b1.setPrice(11);
//                 r1.setBeverage(1);
//             }
//         }

//     }

//     int beverageCount = r1.getBeverage();
//     int foodCount = r1.getFood();
//     int totalPrice = b1.getPrice();

//     cout << "Beverage count: " << beverageCount << endl;
//     cout << "Food count: " << foodCount << endl;

//     // Show relation between Bronco class with Restaurant class
//     Bronco *broncoPtr = &b1;
//     Restaurant *restaurantPtr = broncoPtr;
//     cout << "Total price: " << broncoPtr->getPrice() << endl;
// }