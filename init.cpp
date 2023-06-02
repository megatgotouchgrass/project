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
    cout << "\033[0m ";
}

bool Init::checkIfUserExist()
{
    char response;
    bool response2;

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

    return response2;
};

void Init::mainMenu()
{
    int choice;

    greetings();
    cout << "Welcome! Please choose what would you like to view" << endl
         << endl;

    cout << "\033[1;33m";

    cout << "\033[0m" << endl;

    cout << "1 : Fun Rides" << endl;
    cout << "2 : Restaurant" << endl;
    cout << "3 : Merchandise Shop" << endl;
    cout << "4 : Queue Time" << endl;

    cin >> choice;

    // this switch case function was totally not made by chatgpt (i lied)
    switch (choice)
    {
    case 1:
        std::cout << "You selected Fun Rides. Enjoy the thrill!" << std::endl;
        break;
    case 2:
        std::cout << "You selected Restaurant. Bon appétit!" << std::endl;
        break;
    case 3:
        std::cout << "You selected Merchandise Shop. Happy shopping!" << std::endl;
        break;
    case 4:
        std::cout << "You selected Queue Time. Stay patient, your turn will come!" << std::endl;
        break;
    default:
        std::cout << "Invalid choice. Please select a valid option." << std::endl;
        break;
    }
}