#include "errorHandler.h"

void ErrorHandler::invalidInput()
{
    cout << setw(73) << "Wrong input! Please insert again" << endl
         << endl;
}

void ErrorHandler::limitCapacity()
{
    cout << setw(78) << "Sorry!, There is no available seat left!"
}

void ErrorHandler::fileError()
{
    cout << setw(71) << "Sorry!, file cannot be opened!";
}