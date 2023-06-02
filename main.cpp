#include <iostream>
#include "init.h"
#include "authentication.h"

using namespace std;

int main()
{
    Init init;
    Authentication auth;
    bool userExist;
    char systemRun;

    do
    {
        init.greetings();
        userExist = init.checkIfUserExist();

        if (userExist)
        {
            auth.userLogIn();
        }
        else
        {
            auth.userSignUp();
        }

        init.greetings();
        cout << "Do you wish to go back to home menu? (y/n): ";
        cin >> systemRun;

    } while (systemRun == 'Y' || systemRun == 'y');
};