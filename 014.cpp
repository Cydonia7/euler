#include <iostream>
#include <unordered_map>

using namespace std;

unsigned long long collatzLength(unordered_map<unsigned long long, unsigned long long>& cache, unsigned long long n)
{
    auto item = cache.find(n);

    if (item != cache.end()) {
        return item->second;
    }

    unsigned long long next;
    if (n % 2 == 0) {
        next = n / 2;
    }
    else {
        next = 3 * n + 1;
    }

    cache[n] = 1 + collatzLength(cache, next);

    return cache[n];
}

int main()
{
    unsigned long long longestSequence = 0, result = 0;
    unordered_map<unsigned long long, unsigned long long> cache;
    cache[1] = 1;

    for (unsigned long long i = 2; i < 1000000; i++) {
        unsigned long long length = collatzLength(cache, i);

        if (longestSequence < length) {
            longestSequence = length;
            result = i;
        }
    }

    cout << result << endl;

    return 0;
}
