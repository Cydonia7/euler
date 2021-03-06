#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "lib/BigInteger.h"

using namespace std;

int main()
{
    ifstream file("013.txt");
    string line;
    BigInteger sum(0);

    while (getline(file, line))
    {
        sum += BigInteger(line);
    }

    cout << sum.toString().substr(0, 10) << endl;

    return 0;
}

