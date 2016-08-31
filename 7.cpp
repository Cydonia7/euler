#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int i, p = 1, n = 10001;
    int bound = 2 * n * log(n);
    vector<bool> sieve(bound, true);

    for (i = 2; i < bound; i++) {
        if (sieve[i]) {
            if (p++ == n) {
                break;
            }

            for (int j = 2 * i; j < bound; j += i) {
                sieve[j] = false;
            }
        }
    }

    cout << i << endl;

    return 0;
}
