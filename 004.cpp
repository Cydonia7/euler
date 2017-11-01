#include <iostream>

using namespace std;

int reverse(int n) {
    int result = 0;

    while (n != 0) {
        int digit = n % 10;
        result = result * 10 + digit;
        n /= 10;
    }

    return result;
}

bool isPalindrome(int n) {
    return n == reverse(n);
}

int main()
{
    int largest = 0;
    int lower = 100;
    int upper = 999;

    for (int m = upper; m >= lower; m--) {
        for (int n = upper; n >= lower && upper * n > largest; n--) {
            int p = m * n;

            if (p > largest && isPalindrome(p)) {
                largest = p;
            }
        }
    }

    cout << largest << endl;

    return 0;
}
