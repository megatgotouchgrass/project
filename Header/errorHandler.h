#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include <exception>
#include <iostream>
#include <iomanip>

using namespace std;

class ErrorHandler
{
public:
    void invalidInput();
    void limitCapacity();
    void fileError();
};
#endif