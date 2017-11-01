#include <iostream>
#include <vector>
#include "lib/io.h"
#include "lib/triangleSum.h"

using namespace std;

int main()
{
    cout << maximumPathSum(readNumbersMatrix("067.txt")) << endl;

    return 0;
}
