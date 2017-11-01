#include <iostream>
#include "lib/BigInteger.h"

using namespace std;

int main()
{
    cout << BigInteger(2).power(1000).digitSum() << endl;

    return 0;
}
