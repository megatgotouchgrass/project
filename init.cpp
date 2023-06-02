#include "init.h"
#include <iostream>

using namespace std;

void Init::greetings()
{
    system("cls");

    cout << "                                                                                                                       " << endl;
    cout << ",---.               |                       ,---.                    --.--|                       ,---.          |     " << endl;
    cout << "|    ,---.,---.,   .|---.,---.,---.,---.    |    ,---..    ,,---.      |  |---.,---.,-.-.,---.    |---',---.,---.|__/  " << endl;
    cout << "|    ,---||   ||   ||   |,---||    ,---|    |    |   | \\  / |---'      |  |   ||---'| | ||---'    |    ,---||    |  \\  " << endl;
    cout << "`---'`---^|---'`---|`---'`---^`    `---^    `---'`---'  `'  `---'      `  `   '`---'` ' '`---'    `    `---^`    `   ` " << endl;
    cout << "          |    `---'                                                                                                  " << endl
         << endl;
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