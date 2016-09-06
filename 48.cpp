#include <iostream>
#include "lib/BigInteger.h"

const int Digits = 10;
const long ModuloBase = pow(10, Digits);

using namespace std;

int main()
{
    long sum = 0;

    for (int i = 1; i <= 1000; i++) {
        long power = 1;

        for (int j = 0; j < i; j++) {
            power *= i;
            power %= ModuloBase;
        }

        sum += power;
        sum %= ModuloBase;
    }

    cout << sum << endl;

    return 0;
}

