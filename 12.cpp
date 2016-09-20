#include <iostream>

using namespace std;

int numDivisors(int n)
{
    int limit = n;
    int result = 0;

    if (n == 1) return 1;

    for (int i = 1; i < limit; i++) {
        if (n % i == 0) {
            limit = n / i;

            if (limit != i) {
                result++;
            }

            result++;
        }
    }

    return result;
}

int numDivisorsTriangle(int i)
{
    if (i % 2 == 0) {
        return numDivisors(i / 2) * numDivisors(i + 1);
    }

    return numDivisors(i) * numDivisors((i + 1) / 2);
}

int main()
{
    int i;

    for (i = 1; numDivisorsTriangle(i) < 500; i++) {}

    cout << i * (i + 1) / 2 << endl;
}
