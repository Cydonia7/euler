#include <iostream>
#include "lib/BigInteger.h"

using namespace std;

int main()
{
    cout << BigInteger::factorial(100).digitSum() << endl;
}
