#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    for (int b = 1; b < 1000; b++) {
        for (int a = 1; a < b; a++) {
            int c = sqrt(a * a + b * b);

            if (a + b + c == 1000 && a * a + b * b == c * c) {
                cout << a * b * c << endl;
                break;
            }
        }
    }

    return 0;
}
