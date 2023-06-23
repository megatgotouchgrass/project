#ifndef INIT_H
#define INIT_H
#include <iomanip>
#include "errorHandler.h"

class Init
{

public:
    void greetings();
    ErrorHandler e;

    Init(){};
    bool checkIfUserExist();
    int mainMenu();
    ~Init(){};
};

#endif