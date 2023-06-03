#include "entertainment.h"
#include "init.h"
#include <iostream>
#include <chrono>

using namespace std;

Entertainment::Entertainment(int cap = 0, int wait = 0) : timer(chrono::seconds(wait))
{
     capacity = cap;
     waitingTime = wait;
}

void Entertainment::displayDetails()
{
     cout << "Capacity: " << capacity << endl;
     cout << "Waiting Time: " << waitingTime << endl;
}

void Entertainment::bookAttraction()
{
}

void Entertainment::mainMenu()
{
     Init::greetings();

     int choice;
     bool validChoice = false;

     cout << "Choose a Fun Ride: " << endl;
     cout << "\033[1;35m"; // purple
     cout << "1. Bumper Cars" << endl;
     cout << "2. Carousel" << endl;
     cout << "3. Roller Coaster" << endl;
     cout << "\033[0m"; // white

     while (!validChoice)
     {
          cout << "Enter your choice (1-3): ";
          cin >> choice;
          cout << endl;

          Entertainment *ride;
          switch (choice)
          {
          case 1:
               cout << "  _______" << endl;
               cout << " /|_||_\\`.__" << endl;
               cout << "(   _    _ _\\" << endl;
               cout << "=`-(_)--(_)-'" << endl
                    << endl;
               ride = new BumperCars();
               validChoice = true;
               break;
          case 2:
               cout << "        ,--," << endl;
               cout << "  _ ___/ /`|" << endl;
               cout << " ;( )__, )" << endl;
               cout << "; //   '--;" << endl;
               cout << "  '^    '^" << endl
                    << endl;

               ride = new Carousel();
               validChoice = true;
               break;
          case 3:
               cout << " _                     .===." << endl;
               cout << "|H|        .--.      .:'   `:." << endl;
               cout << "|H|`.     /||||'     ||     ||" << endl;
               cout << "|//||:. .'||||||`.   `:.   .:'" << endl;
               cout << "|:`:.--'||||||||||`--..`=:='... " << endl
                    << endl;
               ride = new RollerCoaster();
               validChoice = true;
               break;
          default:
               cout << "\033[1;31m"; // red
               cout << "Invalid choice! Please try again." << endl;
               cout << "\033[0m";
          }

          if (validChoice)
          {
               cout << "Fun Ride Details--->" << endl;
               ride->displayDetails();

               int seatsToBook;
               cout << "Enter the number of seats to book: ";
               cin >> seatsToBook;

               if (seatsToBook <= ride->getCapacity())
               {
                    ride->updateCapacity(seatsToBook);

                    cout << "\n----------------------" << endl;
                    cout << "Booking Receipt:" << endl;
                    cout << "----------------------" << endl;
                    cout << "\033[1;35m"; // purple
                    cout << "Fun Ride: ";
                    switch (choice)
                    {
                    case 1:
                         cout << "Bumper Cars" << endl;
                         break;
                    case 2:
                         cout << "Carousel" << endl;
                         break;
                    case 3:
                         cout << "Roller Coaster" << endl;
                         break;
                    }
                    cout << "Number of Seats: " << seatsToBook << endl;
                    cout << "Remaining Capacity: " << ride->getCapacity() << endl;
                    cout << "Waiting Time: " << ride->getTime() << endl;
                    cout << "\033[0m";
                    cout << "----------------------" << endl;
               }

               else
               {
                    cout << "\033[1;31m"; // red
                    cout << "Not enough seats available. Please try again." << endl;
               }

               delete ride;
          }
     }
}