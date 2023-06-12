#include "token.h"

using namespace std;

string Token::generateUniqueToken()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(100000, 999999);
    int randomID = distribution(gen);
    ostringstream oss;
    oss << setfill('0') << setw(6) << randomID;
    return oss.str();
}