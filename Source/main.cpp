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

    do
    {
        init.greetings();
        userExist = init.checkIfUserExist();

        if (userExist)
            accessMainMenu = auth.userLogIn();
        else
            accessMainMenu = auth.userSignUp();

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
            }
        };

        cout << endl
             << "Do you wish to go back to home menu? (y/n): ";
        cin >> systemRun;

    } while (systemRun == 'Y' || systemRun == 'y');
};