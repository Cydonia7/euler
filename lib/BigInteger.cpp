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
    vector<part> result(number.decomposition.size() + decomposition.size());

    int mainShift = 0;

    for (int numberPart : number.decomposition) {
        int shift = mainShift++;

        for (int thisPart : decomposition) {
            BigInteger product(thisPart * numberPart);
            
            for (int i = 0; i < product.decomposition.size(); i++) {
                result[shift + i] += product.decomposition[i];

                int index = shift + i;
                while (result[index] >= BASE) {
                    int carry = result[index] / BASE;
                    result[index] %= BASE;
                    result[++index] += carry;
                }
            }

            shift++;
        }
    }

    while (result.back() == 0) {
        result.pop_back();
    }

    return BigInteger(result);
}

BigInteger BigInteger::power(const int number) const
{
    if (number == 1) {
        return *this;
    }
    
    if (number % 2 == 0) {
        BigInteger half = power(number / 2);
        return half * half;
    }

    return power(1) * power(number - 1);
}

bool BigInteger::operator==(const BigInteger& number) const
{
    return decomposition == number.decomposition;
}

bool BigInteger::operator!=(const BigInteger& number) const
{
    return !operator==(number);
}

BigInteger& BigInteger::operator+=(const BigInteger& number)
{
    *this = *this + number;
    return *this;
}

BigInteger& BigInteger::operator*=(const BigInteger& number)
{
    *this = *this * number;
    return *this;
}

BigInteger BigInteger::factorial(const int number)
{
    BigInteger result(1);

    for (int i = 2; i <= number; i++) {
        result *= i;
    }

    return result;
}

int BigInteger::digitSum() const
{
    int result = 0;

    for (char digit : toString()) {
        result += digit - '0';
    }

    return result;
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

string prettyPrint(BigInteger number)
{
    return "BigInteger(\"" + number.toString() + "\")";
}

ostream& operator<<(ostream& stream, const BigInteger& number)
{
    stream << number.toString();
    return stream;
}
