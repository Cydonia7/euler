#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

string numberToSpacelessEnglish(int number)
{
    vector<string> underTwenty = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
                             "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
    vector<string> tens = { "zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

    string result;

    if (number < 20) {
        result = underTwenty[number];
    }
    else if (number < 100) {
        int rest = number % 10;

        result = tens[floor(number / 10.0)];

        if (rest) {
            result += underTwenty[number % 10];
        }
    }
    else if (number < 1000) {
        int rest = number % 100;
        result = underTwenty[floor(number / 100.0)] + "hundred";

        if (rest) {
            result += "and" + numberToSpacelessEnglish(rest);
        }
    }
    else {
        result = "onethousand";
    }

    cout << number << " : " << result << endl;

    return result;
}

int letterCount(int number)
{
    return static_cast<int>(numberToSpacelessEnglish(number).size());
}

int main()
{
    int sum = 0;

    for (int i = 1; i <= 1000; i++)
    {
        sum += letterCount(i);
    }

    cout << sum << endl;

    return 0;
}
