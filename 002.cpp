#include <iostream>

using namespace std;

int main()
{
    int sum = 0;
    int a, b = 1;

    while (b < 4000000) {
        b = a + b;
        a = b - a;

        if (b % 2 == 0) {
            sum += b;
        }
    }

    cout << sum << endl;

    return 0;
}
