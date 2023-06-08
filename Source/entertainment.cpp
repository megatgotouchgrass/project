#include "entertainment.h"
#include "init.h"
#include <iostream>
#include <chrono>

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

void Entertainment::bookEntertainment()
{
     bool validChoice = false;
     int choice;

     cout << endl
          << "What would you like to choose?" << endl
          << endl;

     while (!validChoice)
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
          cout << endl;
     }
}

void Entertainment::mainMenu()
{
     Init::greetings();
     bookEntertainment();
}

void BumperCars::bookEntertainment(){};
void Carousel::bookEntertainment(){};
void RollerCoaster::bookEntertainment(){};