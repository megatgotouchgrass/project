#include "entertainment.h"
#include <iostream>
#include <chrono>
#include <fstream>
#include <sstream>

using namespace std;

Entertainment::Entertainment(int cap = 0, int wait = 0)
{
     capacity = cap;
     waitingTime = wait;
}

void Entertainment::displayDetails()
{
     cout << "Capacity: " << capacity << endl;
     cout << "Waiting Time: " << waitingTime << endl;
}

void Entertainment::bookEntertainment(int choice)
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

     entertainment->bookEntertainment(choice);
}

void Entertainment::mainMenu()
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

     bookEntertainment(choice);
}

#include <fstream>

BumperCars::BumperCars() : Entertainment(2, 5)
{
     // Store capacity and waiting time in a CSV file
     ofstream file("entertainment.csv", ios::app); // Open file in append mode
     if (file.is_open())
     {
          file << "Bumper Cars," << getCapacity() << "," << getTime() << endl; // Write data to the file
          file.close();
          cout << "Capacity and waiting time for Bumper Cars stored successfully." << endl;
     }
     else
     {
          cout << "Error: Unable to open the file." << endl;
     }
}

Carousel::Carousel() : Entertainment(40, 4)
{
     // Store capacity and waiting time in a CSV file
     ofstream file("entertainment.csv", ios::app); // Open file in append mode
     if (file.is_open())
     {
          file << "Carousel," << getCapacity() << "," << getTime() << endl; // Write data to the file
          file.close();
          cout << "Capacity and waiting time for Carousel stored successfully." << endl;
     }
     else
     {
          cout << "Error: Unable to open the file." << endl;
     }
}
void Entertainment::updateWaitingCapacity(const string &entertainmentType, int newCapacity, int newWaitingTime)
{
     ifstream wcFile("entertainment.csv"); // Open waiting_capacity file for reading
     if (wcFile.is_open())
     {
          ofstream tempFile("temp.csv"); // Create a temporary file

          string line;
          while (getline(wcFile, line))
          {
               stringstream ss(line);
               string entertainment;
               int capacityValue;
               int waitingTimeValue;

               if (getline(ss, entertainment, ',') && getline(ss, line, ',') && getline(ss, line))
               {
                    capacityValue = stoi(line);
                    waitingTimeValue = stoi(line);

                    if (entertainment == entertainmentType)
                    {
                         // Update capacity and waiting time
                         capacityValue = newCapacity;
                         waitingTimeValue = newWaitingTime;
                    }

                    // Write the updated values to the temporary file
                    tempFile << entertainment << "," << capacityValue << "," << waitingTimeValue << endl;
               }
          }

          wcFile.close();   // Close the waiting_capacity file
          tempFile.close(); // Close the temporary file

          // Replace the waiting_capacity file with the temporary file
          remove("entertainment.csv");
          rename("temp.csv", "entertainment.csv");

          cout << "Waiting capacity updated successfully!" << endl;
     }
     else
     {
          cout << "Error: Unable to open the waiting_capacity file." << endl;
     }
}

void BumperCars::bookEntertainment(int choice)
{
     cout << "Booking Bumper Cars..." << endl;

     // Save booking information to a CSV file
     ofstream bookingFile("bookings.csv", ios::app); // Open booking file in append mode
     if (bookingFile.is_open())
     {
          bookingFile << auth.getUsername() << ", Bumper Cars, " << capacity << endl; // Write booking data to the file
          bookingFile.close();                                                        // Close the booking file
          cout << "Booking successful!" << endl;
     }
     else
     {
          cout << "Error: Unable to open the booking file." << endl;
     }

     // Update waiting_capacity file
     updateWaitingCapacity("Bumper Cars", capacity - 1, waitingTime + 1);
}

void Carousel::bookEntertainment(int choice)
{
     cout << "Booking Carousel..." << endl;

     // Save booking information to a CSV file
     ofstream bookingFile("bookings.csv", ios::app); // Open booking file in append mode
     if (bookingFile.is_open())
     {
          bookingFile << auth.getUsername() << ", Carousel, " << capacity << endl; // Write booking data to the file
          bookingFile.close();                                                     // Close the booking file
          cout << "Booking successful!" << endl;
     }
     else
     {
          cout << "Error: Unable to open the booking file." << endl;
     }

     // Update waiting_capacity file
     updateWaitingCapacity("Carousel", capacity - 1, waitingTime + 1);
}

void RollerCoaster::bookEntertainment(int choice)
{
     cout << "Booking Roller Coaster..." << endl;

     // Save booking information to a CSV file
     ofstream bookingFile("bookings.csv", ios::app); // Open booking file in append mode
     if (bookingFile.is_open())
     {
          bookingFile << auth.getUsername() << ", Roller Coaster, " << capacity << endl; // Write booking data to the file
          bookingFile.close();                                                           // Close the booking file
          cout << "Booking successful!" << endl;
     }
     else
     {
          cout << "Error: Unable to open the booking file." << endl;
     }

     // Update waiting_capacity file
     updateWaitingCapacity("Roller Coaster", capacity - 1, waitingTime + 1);
}
