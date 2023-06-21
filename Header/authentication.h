#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
#include "init.h"
#include <string>
#include <iomanip>

using namespace std;

class Authentication : public Init
{
private:
    string username;
    string password;

public:
    Authentication(){};
    bool userSignUp();
    bool userLogIn();
    string passwordInput();
    bool updateDatabase(); // to add up new user
    bool checkDatabase();
    string getUsername(); // to determine whether the user is alreaedy in the system
    ~Authentication(){};
};

#endif