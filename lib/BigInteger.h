#pragma once

#include <string>
#include <vector>
#include <cmath>

#define DIGITS_PER_PART 4
#define BASE (int) pow(10, DIGITS_PER_PART)

typedef uint32_t part;

class BigInteger {
    public:
        BigInteger(std::string number);
        BigInteger(int number);

        bool operator==(const BigInteger& number) const;
        bool operator!=(const BigInteger& number) const;

        BigInteger operator+(const BigInteger& number) const;
        BigInteger operator*(const BigInteger& number) const;
        BigInteger power(const int number) const;

        int digitSum() const;

        std::string toString() const;

    private:
        BigInteger(std::vector<part> parts);
        part getPart(int i) const;

        std::vector<part> decomposition;
};

std::string prettyPrint(BigInteger number);

