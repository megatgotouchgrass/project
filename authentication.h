#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
#include "init.h"
#include <string>

using namespace std;

class Authentication : public Init
{
private:
    string username;
    string password;

public:
    void userSignUp();
    void userLogIn();
    string passwordInput();
    void updateDatabase(); // to add up new user
    bool checkDatabase();  // to determine whether the user is alreaedy in the system
};

#endif