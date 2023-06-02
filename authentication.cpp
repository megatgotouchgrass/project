#include "authentication.h"
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

enum TT_Input
{

    // ASCII code of backspace is 8
    BACKSPACE = 8,
    RETURN = 32
};

string Authentication::passwordInput()
{
    string ipt = "";
    char ipt_ch;
    while (true)
    {
        ipt_ch = getch();

        if (ipt_ch < TT_Input::RETURN && ipt_ch != TT_Input::BACKSPACE)
        {
            cout << endl;
            return ipt;
        }

        // Check whether the user
        // pressed backspace
        if (ipt_ch == TT_Input::BACKSPACE)
        {

            // Check if ipt is empty or not
            if (ipt.length() == 0)
                continue;
            else
            {

                // Removes last character
                ipt.pop_back();

                continue;
            }
        }
        ipt.push_back(ipt_ch);
    }
}
void Authentication::userSignUp()
{
    greetings();
    char continueOperation;

    cout << "Do you wish to create a new account? (y/n) : ";
    cin >> continueOperation;

    if (continueOperation == 'Y' || continueOperation == 'y')
    {
        greetings();
        cout << "Enter your username: ";
        cin >> username;

        cout << "Enter your password: ";
        password = passwordInput();

        fflush(stdin);
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
