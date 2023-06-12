#include "merchandise.h"
#include <iostream>
using namespace std;

void Merchandise::mainMenu()
{
     int selection;

     greetings();
     cout << "What shop would you like to choose?" << endl
          << endl;

     cout << "(1) Galactic BootCamp" << endl;
     cout << "               _    _" << endl;
     cout << "              (_\\__/(,_" << endl;
     cout << "              | \\ `_////-._" << endl;
     cout << "  _    _      L_/__ \"=> __/`\\" << endl;
     cout << " (_\\__/(,_    |=====;__/___./" << endl;
     cout << " | \\ `_////-._'-'-'-\"\"\"\"\"\"`" << endl;
     cout << " J_/___\"=> __/`\\" << endl;
     cout << " |=====;__/___./" << endl;
     cout << " '-'-'-\"\"\"\"\"\"\"`" << endl
          << endl;

     cout << "(2) Emporium Park" << endl;
     cout << "                             ___......__             _" << endl;
     cout << "                        _.-'           ~-_       _.=a~~-_" << endl;
     cout << "--=====-.-.-_----------~   .--.       _   -.__.-~ ( ___===>" << endl;
     cout << "              '''--...__  (    \\ \\\\\\ { )       _.-~" << endl;
     cout << "                        =_ ~_  \\\\-~~~//~~~~-=-~" << endl;
     cout << "                         |-=-~_ \\\\   \\\\" << endl;
     cout << "                         |_/   =. )   ~}" << endl;
     cout << "                         |}      ||" << endl;
     cout << "                        //       ||" << endl;
     cout << "                      _//        {{" << endl;
     cout << "                   '='~'          \\\\_    =" << endl;
     cout << "                                   ~~'" << endl;

     cout << "(3) Galaxy Of Wonders" << endl;
     cout << "         _ _" << endl;
     cout << "      ___   ___" << endl;
     cout << "     '~~(`v')~~`" << endl;
     cout << "         |   |" << endl;
     cout << "        /   \\" << endl;
     cout << "      .'`~~~'`." << endl;
     cout << "     /   /\"\\   \\" << endl;
     cout << "    .   / | \\   ." << endl;
     cout << "   /   .  .  .   \\" << endl;
     cout << "  .   /   |   \\   ." << endl;
     cout << " /   .    |    .   \\" << endl;
     cout << ":   /     .     \\   :" << endl;
     cout << "`~.:.     |     .:.~'" << endl;

     cout << endl
          << "Insert selection: ";
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

string Merchandise::generateUniqueToken()
{
     random_device rd;
     mt19937 gen(rd());
     uniform_int_distribution<int> distribution(100000, 999999);
     int randomID = distribution(gen);
     ostringstream oss;
     oss << setfill('0') << setw(6) << randomID;
     return oss.str();
}

void Merchandise::receipt(vector<string> selectedmerchItems)
{
     // Generate a unique token
     string idToken = generateUniqueToken();

     // Calculate the total price
     float totalPrice = calculateTotalPrice(selectedmerchItems);

     // Display the receipt
     cout << "---------------- Receipt ----------------" << endl;
     cout << "ID Token: " << idToken << endl;
     cout << "Total Price: $" << fixed << setprecision(2) << totalPrice << endl;
     cout << "----------------------------------------" << endl;

     // Store the receipt information in a file
     ofstream file("receiptMerchandise.csv", ios::app);
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

     cout << "Available Merchandise in Galactic Bootcamp" << endl;
     for (int i = 0; i < merchItems.size(); i++)
     {
          cout << "(" << i + 1 << ") " << merchItems[i] << " - $" << merchPrices[i] << endl;
     }

     cout << endl;
     vector<string> selectedmerchItems;
     int merchChoice;
     do
     {
          cout << "Select a merch item (enter 0 to finish): ";
          cin >> merchChoice;
          if (merchChoice > 0 && merchChoice <= merchItems.size())
          {
               selectedmerchItems.push_back(merchItems[merchChoice - 1]);
          }
     } while (merchChoice != 0);

     // Perform the booking based on the selected options
     greetings();
     cout << endl;
     cout << "Merchandise selected:" << endl;
     for (const auto &merch : selectedmerchItems)
     {
          cout << merch << endl;
     }
     cout << endl;
     receipt(selectedmerchItems);
}

void ParkEmporium::bookRestaurant()
{
     greetings();

     cout << "Available Merchandise in Park Emporium:" << endl;
     for (int i = 0; i < merchItems.size(); i++)
     {
          cout << "(" << i + 1 << ") " << merchItems[i] << " - $" << merchPrices[i] << endl;
     }

     cout << endl;
     vector<string> selectedmerchItems;
     int merchChoice;
     do
     {
          cout << "Select a merch item (enter 0 to finish): ";
          cin >> merchChoice;
          if (merchChoice > 0 && merchChoice <= merchItems.size())
          {
               selectedmerchItems.push_back(merchItems[merchChoice - 1]);
          }
     } while (merchChoice != 0);

     // Perform the booking based on the selected options
     greetings();

     cout << "Merchandise selected:" << endl;
     for (const auto &merch : selectedmerchItems)
     {
          cout << merch << endl;
     }
     cout << endl;
     receipt(selectedmerchItems);
}

void RealmOfWonders::bookRestaurant()
{
     greetings();

     cout << "Available Merchandise in Realm of Wonders:" << endl;
     for (int i = 0; i < merchItems.size(); i++)
     {
          cout << "(" << i + 1 << ") " << merchItems[i] << " - $" << merchPrices[i] << endl;
     }

     cout << endl;
     vector<string> selectedmerchItems;
     int merchChoice;
     do
     {
          cout << "Select a merch item (enter 0 to finish): ";
          cin >> merchChoice;
          if (merchChoice > 0 && merchChoice <= merchItems.size())
          {
               selectedmerchItems.push_back(merchItems[merchChoice - 1]);
          }
     } while (merchChoice != 0);

     // Perform the booking based on the selected options
     greetings();

     cout << "Merchandise selected:" << endl;
     for (const auto &merch : selectedmerchItems)
     {
          cout << merch << endl;
     }
     cout << endl;
     receipt(selectedmerchItems);
}