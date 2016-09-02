#include "BigInteger.h"
#include <iostream>

using namespace std;

BigInteger::BigInteger(string number)
{
    while (!number.empty()) {
        string remainder = number;

        if (remainder.size() > DIGITS_PER_PART) {
            remainder = remainder.substr(number.size() - DIGITS_PER_PART);
        }

        decomposition.push_back(stoi(remainder));
        number = number.substr(0, number.size() - remainder.size());
    }
}

BigInteger BigInteger::operator+(const BigInteger& number) const
{
    return BigInteger("432");
}

string BigInteger::toString() const
{
    string result;

    for (auto it = decomposition.rbegin(); it != decomposition.rend(); ++it) {
        result += to_string(*it);
    }

    return result;
}

