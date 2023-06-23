#include "merchandise.h"
#include <iostream>
using namespace std;

void Merchandise::mainMenu()
{
     int selection;

     greetings();
     cout << setw(76) << "What shop would you like to choose?" << endl
          << endl;

     cout << setw(45 + 22) << "(1) Galactic BootCamp" << endl;
     cout << setw(45 + 22) << "               _    _" << endl;
     cout << setw(45 + 24) << "              (_\\__/(,_" << endl;
     cout << setw(45 + 28) << "              | \\ `_////-._" << endl;
     cout << setw(45 + 30) << "  _    _      L_/__ \"=> __/`\\" << endl;
     cout << setw(45 + 30) << " (_\\__/(,_    |=====;__/___./" << endl;
     cout << setw(45 + 28) << " | \\ `_////-._'-'-'-\"\"\"\"\"\"`" << endl;
     cout << setw(45 + 17) << " J_/___\"=> __/`\\" << endl;
     cout << setw(45 + 17) << " |=====;__/___./" << endl;
     cout << setw(45 + 16) << " '-'-'-\"\"\"\"\"\"\"`" << endl
          << endl;

     cout << setw(45 + 18) << "(2) Emporium Park" << endl;
     cout << setw(24 + 55) << "                             ___......__             _" << endl;
     cout << setw(24 + 58) << "                        _.-'           ~-_       _.=a~~-_" << endl;
     cout << setw(24 + 60) << "--=====-.-.-_----------~   .--.       _   -.__.-~ ( ___===>" << endl;
     cout << setw(24 + 52) << "              '''--...__  (    \\ \\\\\\ { )       _.-~" << endl;
     cout << setw(24 + 48) << "                        =_ ~_  \\\\-~~~//~~~~-=-~" << endl;
     cout << setw(24 + 40) << "                         |-=-~_ \\\\   \\\\" << endl;
     cout << setw(24 + 41) << "                         |_/   =. )   ~}" << endl;
     cout << setw(24 + 36) << "                         |}      ||" << endl;
     cout << setw(24 + 36) << "                        //       ||" << endl;
     cout << setw(24 + 36) << "                      _//        {{" << endl;
     cout << setw(24 + 43) << "                   '='~'          \\\\_    =" << endl;
     cout << setw(24 + 39) << "                                   ~~'" << endl;

     cout << setw(45 + 22) << "(3) Galaxy Of Wonders" << endl;
     cout << setw(45 + 13) << "         _ _" << endl;
     cout << setw(45 + 16) << "      ___   ___" << endl;
     cout << setw(45 + 17) << "     '~~(`v')~~`" << endl;
     cout << setw(45 + 15) << "         |   |" << endl;
     cout << setw(45 + 14) << "        /   \\" << endl;
     cout << setw(45 + 16) << "      .'`~~~'`." << endl;
     cout << setw(45 + 17) << "     /   /\"\\   \\" << endl;
     cout << setw(45 + 18) << "    .   / | \\   ." << endl;
     cout << setw(45 + 19) << "   /   .  .  .   \\" << endl;
     cout << setw(45 + 20) << "  .   /   |   \\   ." << endl;
     cout << setw(45 + 21) << " /   .    |    .   \\" << endl;
     cout << setw(45 + 22) << ":   /     .     \\   :" << endl;
     cout << setw(45 + 22) << "`~.:.     |     .:.~'" << endl;
     cout << endl
          << setw(65) << "Insert selection: ";
     cin >> selection;

     switch (selection)
     {
     case 1:
     {
          GalacticBootcamp galactic;
          galactic.bookRestaurant();
          break;
     }
     case 2:
     {
          ParkEmporium park;
          park.bookRestaurant();
          break;
     }
     case 3:
     {
          RealmOfWonders realm;
          realm.bookRestaurant();
          break;
     }
     default:
          cout << "Invalid selection!" << endl;
     }
}

void Merchandise::receipt(vector<string> selectedmerchItems)
{
     // Generate a unique token
     string idToken = token.generateUniqueToken();

     // Calculate the total price
     float totalPrice = calculateTotalPrice(selectedmerchItems);

     // Display the receipt
     cout << setw(36 + 42) << "---------------- Receipt ----------------" << endl;
     cout << setw(36 + 11) << "ID Token: " << idToken << endl;
     cout << setw(36 + 15) << "Total Price: $" << fixed << setprecision(2) << totalPrice << endl;
     cout << setw(36 + 41) << "----------------------------------------" << endl;

     // Store the receipt information in a file
     ofstream file("receiptMerchandise.csv", ios::app);
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

float Merchandise::calculateTotalPrice(vector<string> selectedMerchItems)
{
     // Calculate the total price based on the selected merch and beverage items
     // Use the vectors merchItems, merchPrices, beverageItems, beveragePrices

     // For example:
     for (int i = 0; i < selectedMerchItems.size(); ++i)
     {
          int merchIndex = find(merchItems.begin(), merchItems.end(), selectedMerchItems[i]) - merchItems.begin();
          if (merchIndex >= 0 && merchIndex < merchPrices.size())
          {
               totalMerchPrice += merchPrices[merchIndex];
          }
     }

     return totalMerchPrice;
}

GalacticBootcamp::GalacticBootcamp()
{
     merchItems = {"Graphic T-Shirt", "Lightsabers Sword"};
     merchPrices = {20, 25};
}
ParkEmporium::ParkEmporium()
{
     merchItems = {"Dinosaur Plush Toys", "Raptor Bottle"};
     merchPrices = {18, 20};
}

RealmOfWonders::RealmOfWonders()
{
     merchItems = {"Magical Keychain", "Potion Bottle"};
     merchPrices = {7, 17};
}

const vector<string> &Merchandise::getMerchItems() const
{
     return merchItems;
}

const vector<float> &Merchandise::getMerchPrices() const
{
     return merchPrices;
}

void GalacticBootcamp::bookRestaurant()
{
     greetings();

     cout << setw(76) << "Available Merchandise in Galactic Bootcamp" << endl;
     for (int i = 0; i < merchItems.size(); i++)
     {
          cout << setw(42) << "(" << i + 1 << ") " << merchItems[i] << " - $" << merchPrices[i] << endl;
     }

     cout << endl;
     vector<string> selectedmerchItems;
     int merchChoice;
     do
     {
          cout << setw(76) << "Select a merch item (enter 0 to finish): ";
          cin >> merchChoice;
          try
          {
               if (merchChoice > 0 && merchChoice <= merchItems.size())
               {
                    selectedmerchItems.push_back(merchItems[merchChoice - 1]);
               }
               else
               {
                    throw e;
               }
          }
          catch (ErrorHandler e)
          {
               e.invalidInput();
          }
     } while (merchChoice != 0);

     // Perform the booking based on the selected options
     greetings();
     cout << endl;
     cout << setw(40 + 25) << "Merchandise selected:" << endl;
     for (const auto &merch : selectedmerchItems)
     {
          cout << setw(56) << merch << endl;
     }
     cout << endl;
     receipt(selectedmerchItems);
}

void ParkEmporium::bookRestaurant()
{
     greetings();

     cout << setw(76) << "Available Merchandise in Park Emporium:" << endl;
     for (int i = 0; i < merchItems.size(); i++)
     {
          cout << setw(42) << "(" << i + 1 << ") " << merchItems[i] << " - $" << merchPrices[i] << endl;
     }

     cout << endl;
     vector<string> selectedmerchItems;
     int merchChoice;
     do
     {
          cout << setw(76) << "Select a merch item (enter 0 to finish): ";
          cin >> merchChoice;
          try
          {
               if (merchChoice > 0 && merchChoice <= merchItems.size())
               {
                    selectedmerchItems.push_back(merchItems[merchChoice - 1]);
               }
               else
               {
                    throw e;
               }
          }
          catch (ErrorHandler e)
          {
               e.invalidInput();
          }
     } while (merchChoice != 0);

     // Perform the booking based on the selected options
     greetings();
     cout << endl;
     cout << setw(40 + 25) << "Merchandise selected:" << endl;
     for (const auto &merch : selectedmerchItems)
     {
          cout << setw(56) << merch << endl;
     }
     cout << endl;
     receipt(selectedmerchItems);
}

void RealmOfWonders::bookRestaurant()
{
     greetings();

     cout << setw(76) << "Available Merchandise in Realm of Wonders:" << endl;
     for (int i = 0; i < merchItems.size(); i++)
     {
          cout << setw(42) << "(" << i + 1 << ") " << merchItems[i] << " - $" << merchPrices[i] << endl;
     }

     cout << endl;
     vector<string> selectedmerchItems;
     int merchChoice;

     do
     {
          cout << setw(76) << "Select a merch item (enter 0 to finish): ";
          cin >> merchChoice;
          try
          {
               if (merchChoice > 0 && merchChoice <= merchItems.size())
               {
                    selectedmerchItems.push_back(merchItems[merchChoice - 1]);
               }
               else
               {
                    throw e;
               }
          }
          catch (ErrorHandler e)
          {
               e.invalidInput();
          }
     } while (merchChoice != 0);

     // Perform the booking based on the selected options
     greetings();
     cout << endl;
     cout << setw(40 + 25) << "Merchandise selected:" << endl;
     for (const auto &merch : selectedmerchItems)
     {
          cout << setw(56) << merch << endl;
     }
     cout << endl;
     receipt(selectedmerchItems);
}