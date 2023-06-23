#include "init.h"
#include <iostream>

using namespace std;

void Init::greetings()
{
    system("cls");

    cout << "\033[1;34m                                                                                                                  " << endl;
    cout << "\033[0;34m,---.               |                       ,---.                    --.--|                       ,---.          |     " << endl;
    cout << "\033[0;36m|    ,---.,---.,   .|---.,---.,---.,---.    |    ,---..    ,,---.      |  |---.,---.,-.-.,---.    |---',---.,---.|__/  " << endl;
    cout << "\033[0;36m\033[1m|    ,---||   ||   ||   |,---||    ,---|    |    |   | \\  / |---'      |  |   ||---'| | ||---'    |    ,---||    |  \\  " << endl;
    cout << "\033[0;36m`---'`---^|---'`---|`---'`---^`    `---^    `---'`---'  `'  `---'      `  `   '`---'` ' '`---'    `    `---^`    `   ` " << endl;
    cout << "\033[0;34m          |    `---'                                                                                                  " << endl;
    cout << "\033[0m"
         << "";
}

bool Init::checkIfUserExist()
{
    char response;
    bool response2;

    do
    {
        cout << setw(76) << "Have you made an account before? (y/n): ";
        cin >> response;
        try
        {

            if (response == 'Y' || response == 'y')
            {
                response2 = true;
            }
            else if (response == 'N' || response == 'n')
            {
                response2 = false;
            }
            else
            {
                throw e;
            }
        }
        catch (ErrorHandler e)
        {
            e.invalidInput();
        };

    } while (!(response == 'Y' || response == 'y' || response == 'N' || response == 'n'));
    return response2;
};

int Init::mainMenu()
{
    int choice;

    greetings();
    cout << setw(85) << "Welcome! Please choose what would you like to view" << endl
         << endl;

    cout << setw(64) << "1 : Fun Rides"
         << endl;
    cout << setw(65) << "2 : Restaurant" << endl;
    cout << setw(71) << "3 : Merchandise Shop" << endl;
    cout << setw(65) << "4 : Queue Time" << endl;
    cout << setw(69) << "5 : Guest Services" << endl
         << endl;

    do
    {
        cout << setw(60) << "Selection : ";
        cin >> choice;

        try
        {
            if (choice < 1 || choice > 5)
                throw e;
        }
        catch (ErrorHandler e)
        {
            e.invalidInput();
        }

    } while (!(choice > 0 && choice < 6));

    return choice;
}
