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
        cout << "Have you made an account before? (y/n): ";
        cin >> response;

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
            cout << "Wrong input! Please insert again" << endl
                 << endl;
        }
    } while (!(response == 'Y' || response == 'y' || response == 'N' || response == 'n'));
    return response2;
};

int Init::mainMenu()
{
    int choice;

    greetings();
    cout << "Welcome! Please choose what would you like to view" << endl
         << endl;

    cout << "1 : Fun Rides "
         << endl;
    cout << "2 : Restaurant" << endl;
    cout << "3 : Merchandise Shop" << endl;
    cout << "4 : Queue Time" << endl
         << endl;

    cout << "Selection : ";
    cin >> choice;

    // this switch case function was totally not made by chatgpt (i lied)
    switch (choice)
    {
    case 1:
        cout << "You selected Fun Rides. Enjoy the thrill!" << endl;
        break;
    case 2:
        cout << "You selected Restaurant. Bon appetit!" << endl;
        break;
    case 3:
        cout << "You selected Merchandise Shop. Happy shopping!" << endl;
        break;
    case 4:
        cout << "You selected Queue Time. Stay patient, your turn will come!" << endl;
        break;
    default:
        cout << "Invalid choice. Please select a valid option." << endl;
        break;
    }

    return choice;
}
