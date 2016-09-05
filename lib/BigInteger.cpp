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

BigInteger::BigInteger(int number)
{
    while (number > 0) {
        decomposition.push_back(number % BASE);
        number /= BASE;
    }
}

BigInteger::BigInteger(std::vector<part> parts) : decomposition(parts)
{
}

part BigInteger::getPart(int i) const
{
    return decomposition.size() > i ? decomposition[i] : 0;
}

BigInteger BigInteger::operator+(const BigInteger& number) const
{
    vector<part> result;
    int carry = 0;

    for (int i = 0; i < max(decomposition.size(), number.decomposition.size()); i++) {
        part sum = getPart(i) + number.getPart(i) + carry;
        carry = 0;

        if (sum >= BASE) {
            carry = sum / BASE;
            sum = sum % BASE;
        }

        result.push_back(sum);
    }

    if (carry > 0) {
        result.push_back(carry);
    }

    return BigInteger(result);
}

BigInteger BigInteger::operator*(const BigInteger& number) const
{
    return BigInteger("123");
}

bool BigInteger::operator==(const BigInteger& number) const
{
    return decomposition == number.decomposition;
}

bool BigInteger::operator!=(const BigInteger& number) const
{
    return !operator==(number);
}

string BigInteger::toString() const
{
    string result;

    for (auto it = decomposition.rbegin(); it != decomposition.rend(); ++it) {
        string part = to_string(*it);
        result += string(DIGITS_PER_PART - part.size(), '0') + part;
    }

    result.erase(0, result.find_first_not_of('0'));

    return result;
}

std::string prettyPrint(BigInteger number)
{
    return "BigInteger(\"" + number.toString() + "\")";
}

