#include "guestServices.h"
#include <iostream>
using namespace std;

GuestServices::GuestServices(string n, string x, string y, string r) : name(n), locationX(x), locationY(y), remarks(r){};

void GuestServices::showServices()
{

    cout << "    "
         << "The " << name << " is located at"
         << "(" << locationX << "," << locationY << "). "
         << "Remarks: " << remarks;
    cout << endl;
};