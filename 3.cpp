#include <iostream>

using namespace std;

int main()
{
    long n = 600851475143;
    int i;

    for (i = 2; n != 1; i++) {
        while (n % i == 0) {
            n /= i;
        }
    }

    cout << i - 1 << endl;

    return 0;
}
