#include "authentication.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

enum TT_Input
{

    // ASCII code of backspace is 8
    BACKSPACE = 8,
    RETURN = 32
};

bool Authentication::userSignUp()
{
    greetings();
    char continueOperation;

    do
    {
        cout << setw(80) << "Do you wish to create a new account? (y/n) : ";
        cin >> continueOperation;
        if (continueOperation == 'Y' || continueOperation == 'y')
        {
            greetings();
            cout << setw(62) << "Enter your username: ";
            cin >> username;

            cout << setw(62) << "Enter your password: ";
            cin >> password;

            updateDatabase();
            return true;
        }
        else if (continueOperation == 'N' || continueOperation == 'n')
        {
            return false;
        };
    } while (!(continueOperation == 'Y' || continueOperation == 'y' || continueOperation == 'N' || continueOperation == 'n'));

    return true;
};

bool Authentication::userLogIn()
{
    greetings();
    char continueOperation;
    bool accessed;

    cout << setw(86) << "Do you wish to login to the existing account? (y/n) : ";
    cin >> continueOperation;
    do
    {
        if (continueOperation == 'Y' || continueOperation == 'y')
        {

            greetings();
            cout << setw(62) << "Enter your username: ";
            cin >> username;

            cout << setw(62) << "Enter your password: ";
            cin >> password;

            accessed = checkDatabase();
        }
        else if (continueOperation == 'N' || continueOperation == 'n')
        {
            return false;
        }
    } while (!(continueOperation == 'Y' || continueOperation == 'y' || continueOperation == 'N' || continueOperation == 'n'));

    if (accessed)
    {
        return true;
    }
    else
    {
        return false;
    }
};

bool Authentication::updateDatabase()
{
    ofstream file("users.csv", ios_base::app);
    if (!file)
    {
        cerr << "Error opening file" << endl;
        return false;
    }
    else
    {
        if (file.tellp() != 0)
        {
            file << endl;
        }

        file << username << ", " << password << endl;
        file.close();

        greetings();
        return true;
    }
}

bool Authentication::checkDatabase()
{
    string line, fileUsername, filePassword;
    ifstream file("users.csv");
    bool found;

    if (!file)
    {
        cerr << "Error opening file" << endl;
        return false;
    };

    while (getline(file, line))
    {
        stringstream ss(line);
        getline(ss, fileUsername, ',');
        getline(ss, filePassword, ',');

        if (username == fileUsername && password == filePassword)
        {
            found = true;
            break;
        }
    }

    file.close();

    return found;
}

string Authentication::getUsername()
{
    return username;
}
