#include <iostream>
#include "lib/BigInteger.h"

using namespace std;

int main()
{
    string power = BigInteger(2).power(1000).toString();
    int result = 0;

    for (char digit : power) {
        result += digit - '0';
    }

    cout << result << endl;

    return 0;
}
