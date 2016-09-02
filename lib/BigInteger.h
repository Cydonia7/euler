#pragma once

#include <string>
#include <vector>

#define DIGITS_PER_PART 4

class BigInteger {
    public:
        BigInteger(std::string number);
        std::string toString() const;

    private:
        std::vector<uint32_t> decomposition;
};

