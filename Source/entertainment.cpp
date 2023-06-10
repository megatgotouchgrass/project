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

void Entertainment::displayDetails()
{
     cout << "Capacity: " << capacity << endl;
     cout << "Waiting Time: " << waitingTime << endl;
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

BumperCars::BumperCars()
{
     // Store capacity and waiting time in a CSV file
     ofstream file("entertainment.csv", ios::app); // Open file in append mode
     if (file.is_open())
     {
          file << "Bumper Cars," << getCapacity() << " ," << getTime() << endl; // Write data to the file
          file.close();
          cout << "Capacity and waiting time for Bumper Cars stored successfully." << endl;
     }
     else
     {
          cout << "Error: Unable to open the file." << endl;
     }
}

Carousel::Carousel()
{
     // Store capacity and waiting time in a CSV file
     ofstream file("entertainment.csv", ios::app); // Open file in append mode
     if (file.is_open())
     {
          file << "Carousel," << getCapacity() << ", " << getTime() << endl; // Write data to the file
          file.close();
          cout << "Capacity and waiting time for Carousel stored successfully." << endl;
     }
     else
     {
          cout << "Error: Unable to open the file." << endl;
     }
}
RollerCoaster::RollerCoaster()
{
     // Store capacity and waiting time in a CSV file
     ofstream file("entertainment.csv", ios::app); // Open file in append mode
     if (file.is_open())
     {
          file << "Roller Coaster," << getCapacity() << ", " << getTime() << endl; // Write data to the file
          file.close();
          cout << "Capacity and waiting time for Roller Coaster stored successfully." << endl;
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
                    tempFile << entertainment << ", " << capacityValue << ", " << waitingTimeValue << endl;
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

void BumperCars::bookEntertainment(int choice, Authentication &auth)
{
     int queueSize;
     cout
         << "How many people will join the ride?";
     cin >> queueSize;
     cout << endl;

     cout
         << "Booking Bumper Cars..." << endl;
     string idToken = generateUniqueToken();
     // Save booking information to a CSV file
     updateWaitingCapacity("Bumper Cars", capacity - queueSize, waitingTime + 1);

     ofstream bookingFile("bookings.csv", ios::app); // Open booking file in append mode
     if (bookingFile.is_open())
     {
          bookingFile << auth.getUsername() << ", Bumper Cars, " << capacity << ", " << idToken << endl; // Write booking data to the file
          bookingFile.close();                                                                           // Close the booking file
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
         << "How many people will join the ride?";
     cin >> queueSize;
     cout << endl
          << "Booking Carousel..." << endl;
     string idToken = generateUniqueToken();
     // Save booking information to a CSV file
     ofstream bookingFile("bookings.csv", ios::app); // Open booking file in append mode
     updateWaitingCapacity("Carousel", capacity - queueSize, waitingTime + 1);
     if (bookingFile.is_open())
     {
          bookingFile << auth.getUsername() << ", Carousel, " << capacity << ", " << idToken << endl; // Write booking data to the file
          bookingFile.close();                                                                        // Close the booking file
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
         << "How many people will join the ride?";
     cin >> queueSize;
     cout << endl
          << "Booking Roller Coaster..." << endl;
     string idToken = generateUniqueToken();
     // Save booking information to a CSV file
     ofstream bookingFile("bookings.csv", ios::app); // Open booking file in append mode
     updateWaitingCapacity("Roller Coaster", capacity - queueSize, waitingTime + 1);
     if (bookingFile.is_open())
     {
          bookingFile << auth.getUsername() << ", Roller Coaster, " << capacity << ", " << idToken << endl; // Write booking data to the file
          bookingFile.close();                                                                              // Close the booking file
          cout << "Booking successful!" << endl;
     }
     else
     {
          cout << "Error: Unable to open the booking file." << endl;
     }

     // Update waiting_capacity file
}
