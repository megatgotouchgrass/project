#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
#include "init.h"

class Authentication : public Init
{
public:
    void userSignUp();
    void userLogIn();
};

#endif