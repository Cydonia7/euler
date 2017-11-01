#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int d(int n, vector<int>& bounds)
{
    auto bound = bounds.begin();
    int digits = 0;

    for (; bound != bounds.end(); bound++, digits++) {
        if (*bound >= n) {
            break;
        }
    }

    int maxBound = *bound;
    int minBound = *--bound + 1;

    int number = pow(10, digits - 1) + (n - minBound) / digits;
    int numberDigit = (n - minBound) % digits;

    return (to_string(number).at(numberDigit) - '0');
}

int bound(int n)
{
    return (n * pow(10, n + 1) - (n + 1) * pow(10, n) + 1) / 9;
}

int main()
{
    vector<int> digits = { 1, 10, 100, 1000, 10000, 100000, 1000000 };
    vector<int> bounds = { 0 };
    int result = 1;

    while (bounds.back() < digits.back()) {
        bounds.push_back(bound(bounds.size()));
    }

    for (int digit : digits) {
        result *= d(digit, bounds);
    }
    
    cout << result << endl;

    return 0;
}
