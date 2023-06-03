#include <iostream>
#include "init.h"
#include "authentication.h"
#include "attraction.h"

using namespace std;

int main()
{
    Init init;
    Authentication auth;
    Attraction attraction;

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
            init.mainMenu();

        cout << endl
             << "Do you wish to go back to home menu? (y/n): ";
        cin >> systemRun;

    } while (systemRun == 'Y' || systemRun == 'y');
};