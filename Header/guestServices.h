#ifndef GUESTSERVICES_H
#define GUESTSERVICES_H

#include <iostream>
#include <string>
#include "init.h"

using namespace std;

class GuestServices : public Init
{
    string name;
    string locationX;
    string locationY;
    string remarks;

public:
    GuestServices(string n, string x, string y, string r);
    void showServices();
};

#endif