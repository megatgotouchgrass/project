#include "errorHandler.h"

void ErrorHandler::invalidInput()
{
    cout << setw(73) << "Wrong input! Please insert again" << endl
         << endl;
}

void ErrorHandler::fileError()
{
    cout << setw(71) << "Sorry!, file cannot be opened!";
}