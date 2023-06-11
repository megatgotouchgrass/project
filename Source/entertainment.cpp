#include "entertainment.h"
#include <iostream>
#include <chrono>
#include <fstream>
#include <sstream>
#include <random>
#include <iomanip>

using namespace std;

string Entertainment::generateUniqueToken()
{
     random_device rd;
     mt19937 gen(rd());
     uniform_int_distribution<int> distribution(100000, 999999);
     int randomID = distribution(gen);
     ostringstream oss;
     oss << setfill('0') << setw(6) << randomID;
     return oss.str();
}
void Entertainment::bookEntertainment(int choice, Authentication &auth)
{

     Entertainment *entertainment = nullptr;
     switch (choice)
     {
     case 1:
     {
          entertainment = new BumperCars();
          break;
     }
     case 2:
          entertainment = new Carousel();
          break;

     case 3:
          entertainment = new RollerCoaster();
          break;
     }

     entertainment->bookEntertainment(choice, auth);
}

void Entertainment::mainMenu(Authentication &auth)
{
     greetings();
     bool validChoice = false;
     int choice;

     cout << endl
          << "What would you like to choose?" << endl
          << endl;

     do
     {
          cout << "(1) Bumper Cars" << endl;
          cout << "  _______" << endl;
          cout << " /|_||_\\`.__" << endl;
          cout << "(   _    _ _\\" << endl;
          cout << "=`-(_)--(_)-'" << endl
               << endl;

          cout << "(2) Carousel" << endl;
          cout << "        ,--," << endl;
          cout << "  _ ___/ /`|" << endl;
          cout << " ;( )__, )" << endl;
          cout << "; //   '--;" << endl;
          cout << "  '^    '^" << endl
               << endl;

          cout << "(3) Roller Coaster" << endl;
          cout << " _                     .===." << endl;
          cout << "|H|        .--.      .:'   `:." << endl;
          cout << "|H|`.     /||||'     ||     ||" << endl;
          cout << "|//||:. .'||||||`.   `:.   .:'" << endl;
          cout << "|:`:.--'||||||||||`--..`=:='... " << endl
               << endl;

          cout << "Selection: ";
          cin >> choice;
     } while (!(choice > 0 && choice < 4));

     bookEntertainment(choice, auth);
}

int Entertainment::getCapacityFromCSV(const string &filename, const string &rideName)
{
     ifstream file(filename); // Open the file for reading
     if (file.is_open())
     {
          string line;
          while (getline(file, line))
          {
               istringstream iss(line);
               string name;
               string capacityStr; // Store the capacity as a string

               if (getline(iss, name, ',') && getline(iss, capacityStr, ','))
               {
                    // Trim leading/trailing whitespaces from the ride name
                    name.erase(0, name.find_first_not_of(" \t"));
                    name.erase(name.find_last_not_of(" \t") + 1);

                    // Check if the name matches
                    if (name == rideName)
                    {
                         int capacity = stoi(capacityStr); // Convert the capacity string to an integer
                         // Successfully found the capacity
                         file.close();
                         return capacity;
                    }
               }
          }
          file.close();
     }
     return -1; // Return -1 if ride name is not found or error occurs
}

BumperCars::BumperCars()
{
     // Getting data from a file
     capacity = getCapacityFromCSV("entertainment.csv", "Bumper Cars");
     if (capacity != -1)
     {
          cout << "Capacity: " << capacity << endl;
     }
     else
     {
          cout << "Error: Unable to find capacity for Roller Coaster or open the file." << endl;
     }
}

Carousel::Carousel()
{
     // Getting data from a file

     capacity = getCapacityFromCSV("entertainment.csv", "Carousel");
     if (capacity != -1)
     {
          cout << "Capacity: " << capacity << endl;
     }
     else
     {
          cout << "Error: Unable to find capacity for Roller Coaster or open the file." << endl;
     }
}
RollerCoaster::RollerCoaster()
{
     // Getting data from a file
     capacity = getCapacityFromCSV("entertainment.csv", "Roller Coaster");
     if (capacity != -1)
     {
          cout << "Capacity: " << capacity << endl;
     }
     else
     {
          cout << "Error: Unable to find capacity for Roller Coaster or open the file." << endl;
     }
}

void Entertainment::updateCapacity(const string &rowToUpdate, int newCapacity)
{
     ifstream file("entertainment.csv"); // Open the CSV file for reading

     if (!file)
     {
          cout << "Error opening file." << endl;
          return;
     }

     vector<string> rows;
     string line;

     // Read each line from the file and store it in a vector
     while (getline(file, line))
     {
          rows.push_back(line);
     }

     file.close(); // Close the file

     bool found = false;
     for (string &row : rows)
     {
          stringstream ss(row);
          string item;

          // Split the row into two parts: name and capacity
          getline(ss, item, ',');
          string name = item;
          getline(ss, item, ',');
          int capacity = stoi(item);

          // Check if the row name matches the user input
          if (name == rowToUpdate)
          {
               row = rowToUpdate + ", " + to_string(newCapacity); // Update the row
               found = true;
               break;
          }
     }

     if (!found)
     {
          cout << "Row not found." << endl;
          return;
     }

     ofstream outfile("entertainment.csv"); // Open the CSV file for writing

     if (!outfile)
     {
          cout << "Error opening file." << endl;
          return;
     }

     // Write the updated rows to the file
     for (const string &row : rows)
     {
          outfile << row << endl;
     }

     outfile.close(); // Close the file
     cout << "File updated successfully." << endl;
}

void BumperCars::bookEntertainment(int choice, Authentication &auth)
{

     int queueSize = 0;
     cout
         << "How many people will join the ride?: ";
     cin >> queueSize;
     cout << endl;

     cout
         << "Booking Bumper Cars..." << endl;
     string idToken = generateUniqueToken();

     // Save booking information to a CSV file
     updateCapacity("Bumper Cars", capacity - queueSize);

     ofstream bookingFile("bookings.csv", ios::app); // Open booking file in append mode
     if (bookingFile.is_open())
     {
          bookingFile << auth.getUsername() << ", Bumper Cars, " << queueSize << ", " << idToken << endl; // Write booking data to the file
          bookingFile.close();                                                                            // Close the booking file
          cout << "Booking successful!" << endl;
     }
     else
     {
          cout << "Error: Unable to open the booking file." << endl;
     }

     // Update waiting_capacity file
}

void Carousel::bookEntertainment(int choice, Authentication &auth)
{
     int queueSize;
     cout
         << "How many people will join the ride?: ";
     cin >> queueSize;
     cout << endl
          << "Booking Carousel..." << endl;
     string idToken = generateUniqueToken();

     // Save booking information to a CSV file
     updateCapacity("Carousel", capacity - queueSize);

     ofstream bookingFile("bookings.csv", ios::app); // Open booking file in append mode
     if (bookingFile.is_open())
     {
          bookingFile << auth.getUsername() << ", Carousel, " << queueSize << ", " << idToken << endl; // Write booking data to the file
          bookingFile.close();                                                                         // Close the booking file
          cout << "Booking successful!" << endl;
     }
     else
     {
          cout << "Error: Unable to open the booking file." << endl;
     }

     // Update waiting_capacity file
}

void RollerCoaster::bookEntertainment(int choice, Authentication &auth)
{
     int queueSize;
     cout
         << "How many people will join the ride?: ";
     cin >> queueSize;
     cout << endl
          << "Booking Roller Coaster..." << endl;
     string idToken = generateUniqueToken();

     // Save booking information to a CSV file
     updateCapacity("Roller Coaster", capacity - queueSize);

     ofstream bookingFile("bookings.csv", ios::app); // Open booking file in append mode

     if (bookingFile.is_open())
     {
          bookingFile << auth.getUsername() << ", Roller Coaster, " << queueSize << ", " << idToken << endl; // Write booking data to the file
          bookingFile.close();                                                                               // Close the booking file
          cout << "Booking successful!" << endl;
     }
     else
     {
          cout << "Error: Unable to open the booking file." << endl;
     }

     // Update waiting_capacity file
}
