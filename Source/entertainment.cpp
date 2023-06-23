#include "entertainment.h"
#include <iostream>
#include <chrono>
#include <fstream>
#include <sstream>
#include <random>
#include <iomanip>

using namespace std;

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
          << setw(75) << "What would you like to choose?" << endl
          << endl;

     do
     {
          try
          {
               cout << setw(67) << "(1) Bumper Cars" << endl;
               cout << setw(62) << "  _______" << endl;
               cout << setw(66) << " /|_||_\\`.__" << endl;
               cout << setw(67) << "(   _    _ _\\" << endl;
               cout << setw(67) << "=`-(_)--(_)-'" << endl
                    << endl;

               cout << setw(64) << "(2) Carousel" << endl;
               cout << setw(54 + 12) << "        ,--," << endl;
               cout << setw(54 + 12) << "  _ ___/ /`|" << endl;
               cout << setw(54 + 10) << " ;( )__, )" << endl;
               cout << setw(54 + 11) << "; //   '--;" << endl;
               cout << setw(54 + 10) << "  '^    '^" << endl
                    << endl;

               cout << setw(70) << "(3) Roller Coaster" << endl;
               cout << setw(46 + 28) << " _                     .===." << endl;
               cout << setw(46 + 30) << "|H|        .--.      .:'   `:." << endl;
               cout << setw(46 + 30) << "|H|`.     /||||'     ||     ||" << endl;
               cout << setw(46 + 30) << "|//||:. .'||||||`.   `:.   .:'" << endl;
               cout << setw(46 + 32) << "|:`:.--'||||||||||`--..`=:='... " << endl
                    << endl;

               cout << setw(65) << "Selection: ";
               cin >> choice;

               if (choice < 1 || choice > 3)
                    throw e;
          }
          catch (ErrorHandler e)
          {
               e.invalidInput();
          }
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
          cout << endl;
          cout << setw(64) << "Capacity: " << capacity << endl
               << endl;
     }
     else
     {
          cout << setw(92) << "Error: Unable to find capacity for Roller Coaster or open the file." << endl;
     }
}

Carousel::Carousel()
{
     // Getting data from a file

     capacity = getCapacityFromCSV("entertainment.csv", "Carousel");
     if (capacity != -1)
     {
          cout << setw(64) << "Capacity: " << capacity << endl;
     }
     else
     {
          cout << setw(92) << "Error: Unable to find capacity for Roller Coaster or open the file." << endl;
     }
}
RollerCoaster::RollerCoaster()
{
     // Getting data from a file
     capacity = getCapacityFromCSV("entertainment.csv", "Roller Coaster");
     if (capacity != -1)
     {
          cout << setw(64) << "Capacity: " << capacity << endl;
     }
     else
     {
          cout << setw(92) << "Error: Unable to find capacity for Roller Coaster or open the file." << endl;
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

          // Split the column into two parts: name and capacity
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
}

void Entertainment::showBookings(Authentication &auth)
{
     greetings();
     ifstream bookingsFile("bookings.csv");
     if (bookingsFile.is_open())
     {
          string line;
          while (getline(bookingsFile, line))
          {
               istringstream iss(line);
               string field;
               vector<string> fields;

               // Split the line into fields
               while (getline(iss, field, ','))
               {
                    fields.push_back(field);
               }

               // Display the booking information
               if (fields[0] == auth.getUsername())
               {
                    cout << setw(20) << "Entertainment: " << fields[1] << "          ";
                    cout << "Queue Time : " << fields[5] << "          ";
                    cout << "Ticket ID : " << fields[3];
                    cout << endl;
               }
          }
          bookingsFile.close();
     }
     else
     {
          cout << "Error: Unable to open the bookings file." << endl;
     }
}

void BumperCars::bookEntertainment(int choice, Authentication &auth)
{

     int queueSize = 0;
     try
     {
          do
          {

               cout
                   << setw(40 + 37) << "How many people will join the ride?: ";
               cin >> queueSize;
               cout << endl;

               if (capacity - queueSize < 0)
               {
                    throw e;
               }
          } while (capacity - queueSize < 0);
     }
     catch (ErrorHandler e)
     {
          e.limitCapacity();
     }

     cout
         << setw(50 + 20) << "Booking Bumper Cars..." << endl;
     string idToken = token.generateUniqueToken();

     updateCapacity("Bumper Cars", capacity - queueSize);

     ofstream bookingFile("bookings.csv", ios::app); // Open booking file in append mode
     if (bookingFile.is_open())
     {
          bookingFile << auth.getUsername() << ", Bumper Cars, " << queueSize << ", " << idToken << ", " << time->getCurrentTime() << ", " << time->getWaitingTime("BumperCars") << endl; // Write booking data to the file
          bookingFile.close();                                                                                                                                                            // Close the booking file
          cout << setw(48 + 19 + 10) << "Booking successful! Here is your Ticket ID: " << idToken << endl;
          cout << setw(48 + 19 + 13) << "Please scan it at the entrance of the ride!" << endl;
     }
     else
     {
          cout << setw(40 + 39) << "Error: Unable to open the booking file." << endl;
     }
}

void Carousel::bookEntertainment(int choice, Authentication &auth)
{

     int queueSize = 0;
     try
     {
          do
          {

               cout
                   << setw(40 + 37) << "How many people will join the ride?: ";
               cin >> queueSize;
               cout << endl;

               if (capacity - queueSize < 0)
               {
                    throw e;
               }
          } while (capacity - queueSize < 0);
     }
     catch (ErrorHandler e)
     {
          e.limitCapacity();
     }

     cout << setw(50 + 20) << "Booking Carousel..." << endl;
     string idToken = token.generateUniqueToken();

     updateCapacity("Carousel", capacity - queueSize);

     ofstream bookingFile("bookings.csv", ios::app); // Open booking file in append mode
     if (bookingFile.is_open())
     {
          bookingFile << auth.getUsername() << ", Carousel, " << queueSize << ", " << idToken << ", " << time->getCurrentTime() << ", " << time->getWaitingTime("Carousel") << endl; // Write booking data to the file
          bookingFile.close();                                                                                                                                                       // Close the booking file
          cout << setw(48 + 19 + 10) << "Booking successful! Here is your Ticket ID: " << idToken << endl;
          cout << setw(48 + 19 + 13) << "Please scan it at the entrance of the ride!" << endl;
     }
     else
     {
          cout << setw(40 + 39) << "Error: Unable to open the booking file." << endl;
     }
}

void RollerCoaster::bookEntertainment(int choice, Authentication &auth)
{
     int queueSize = 0;
     try
     {
          do
          {

               cout
                   << setw(40 + 37) << "How many people will join the ride?: ";
               cin >> queueSize;
               cout << endl;

               if (capacity - queueSize < 0)
               {
                    throw e;
               }
          } while (capacity - queueSize < 0);
     }
     catch (ErrorHandler e)
     {
          e.limitCapacity();
     }

     cout << endl
          << setw(50 + 20) << "Booking Roller Coaster..." << endl;
     string idToken = token.generateUniqueToken();

     updateCapacity("Roller Coaster", capacity - queueSize);

     ofstream bookingFile("bookings.csv", ios::app); // Open booking file in append mode

     if (bookingFile.is_open())
     {
          bookingFile << auth.getUsername() << ", Roller Coaster, " << queueSize << ", " << idToken << ", " << time->getCurrentTime() << ", " << time->getWaitingTime("RollerCoaster") << endl; // Write booking data to the file
          bookingFile.close();                                                                                                                                                                  // Close the booking file
          cout << setw(48 + 19 + 10) << "Booking successful! Here is your Ticket ID: " << idToken << endl;
          cout << setw(48 + 19 + 13) << "Please scan it at the entrance of the ride!" << endl;
     }
     else
     {
          cout << setw(40 + 39) << "Error: Unable to open the booking file." << endl;
     }
}
