#pragma once

#include <string>
#include <vector>
#include <cmath>

#define DIGITS_PER_PART 4
#define BASE pow(10, DIGITS_PER_PART)

class BigInteger {
    public:
        BigInteger(std::string number);
        std::string toString() const;
        BigInteger operator+(const BigInteger& number) const;

    private:
        std::vector<uint32_t> decomposition;
};

