#include <iostream>
#include "init.h"
#include "authentication.h"
#include "entertainment.h"
#include "restaurant.h"
#include "merchandise.h"
#include "guestServices.h"

using namespace std;

int main()
{
    Init init;
    Authentication auth;
    Entertainment entertainment;
    Restaurant restaurant;
    Merchandise merchandise;

    // Array of Object
    GuestServices guestservice[3] = {
        GuestServices("Information Counter", "3.919293", "2.123324", "Near the Roller Coaster"),
        GuestServices("Smoking Area", "19.2313412", "5.1234312", "Right by Bronco Bistro"),
        GuestServices("Locker Rooms", "3.0003", "2.129924", "The opposite of Galaxy Wonders Merchandise Store"),
    };

    int selection;
    bool userExist;
    bool accessMainMenu;
    char systemRun;

    init.greetings();

    userExist = init.checkIfUserExist();

    if (userExist)
        accessMainMenu = auth.userLogIn();
    else
        accessMainMenu = auth.userSignUp();
    do
    {

        if (accessMainMenu)
        {
            selection = init.mainMenu();

            switch (selection)
            {
            case 1:
                entertainment.mainMenu(auth);
                break;
            case 2:
                restaurant.mainMenu();
                break;
            case 3:
                merchandise.mainMenu();
                break;
            case 4:
                entertainment.showBookings(auth);
                break;
            case 5:
                cout << endl;
                init.greetings();
                for (int i = 0; i < 3; i++)
                {
                    guestservice[i].showServices();
                }
                break;
            }
        };

        cout << endl
             << setw(80) << "Do you wish to go back to home menu? (y/n): ";
        cin >> systemRun;

    } while (systemRun == 'Y' || systemRun == 'y');
};