#ifndef TOKEN_H
#define TOKEN_H

#include <random>
#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>
using namespace std;

class Token
{
public:
    Token(){};
    string generateUniqueToken();
    ~Token(){};
};

#endif