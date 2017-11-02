#include <iostream>

using namespace std;

struct date
{
    int dayOfWeek;
    int month;
    int year;
};

bool isLeapYear(int year)
{
    if (year % 4 != 0) {
        return false;
    }

    if (year % 100 != 0) {
        return true;
    }

    return year % 400 == 0;

}

int numberOfDays(date date)
{
    if (date.month == 8 || date.month == 3 || date.month == 5 || date.month == 10) {
        return 30;
    }

    if (date.month == 1) {
        if (isLeapYear(date.year)) {
            return 29;
        }

        return 28;
    }

    return 31;
}

date nextMonth(date current)
{
    date next = {};
    next.dayOfWeek = (current.dayOfWeek + numberOfDays(current)) % 7;
    next.month = (current.month + 1) % 12;
    next.year = current.year + ((next.month == 0) ? 1 : 0);

    return next;
}

int main()
{
    date start = {};
    start.dayOfWeek = 1; // Tuesday
    start.month = 0; // January
    start.year = 1901;

    int result = 0;

    while (start.year != 2000 || start.month != 11) {
        start = nextMonth(start);

        if (start.dayOfWeek == 6) {
            result++;
        }
    }

    cout << result << endl;

    return 0;
}
