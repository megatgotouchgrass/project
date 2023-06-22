#include <iostream>
#include "init.h"
#include "authentication.h"
#include "entertainment.h"
#include "restaurant.h"
#include "merchandise.h"

using namespace std;

int main()
{
    Init init;
    Authentication auth;
    Entertainment entertainment;
    Restaurant restaurant;
    Merchandise merchandise;

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
            }
        };

        cout << endl
             << setw(80) << "Do you wish to go back to home menu? (y/n): ";
        cin >> systemRun;

    } while (systemRun == 'Y' || systemRun == 'y');
};