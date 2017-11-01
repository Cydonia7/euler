#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    long n = 2000000, sum = 0;
    vector<bool> sieve(n, true);

    for (int i = 2; i < n; i++) {
        if (sieve[i]) {
            sum += i;

            for (int j = 2 * i; j < n; j += i) {
                sieve[j] = false;
            }
        }
    }

    cout << sum << endl;

    return 0;
}
