#ifndef INIT_H
#define INIT_H
#include <iomanip>
#include "errorHandler.h"

class Init
{
public:
    ErrorHandler e;

    Init(){};
    void greetings();
    bool checkIfUserExist();
    int mainMenu();
    ~Init(){};
};

#endif