#include "authentication.h"
#include <iostream>

using namespace std;

void Authentication::userSignUp()
{
    greetings();
    char continueOperation;

    cout << "Do you wish to create a new account? (y/n) : ";
    cin >> continueOperation;

    if (continueOperation == 'Y' || continueOperation == 'y')
    {
    }
};

void Authentication::userLogIn()
{

    greetings();
    char continueOperation;

    cout << "Do you wish to login to the existing account? (y/n) : ";
    cin >> continueOperation;

    if (continueOperation == 'Y' || continueOperation == 'y')
    {
    }
};
