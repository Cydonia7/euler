#include <iostream>
#include <vector>
#include "lib/io.h"

using namespace std;

const int Size = 20;

int main()
{
    vector<vector<int> > matrix = readNumbersMatrix("011.txt");
    int result = 0;

    // Horizontal
    for (int row = 0; row < Size; row++)
    {
        for (int column = 0; column < Size - 3; column++)
        {
            result = max(result, matrix[row][column] * matrix[row][column + 1] * matrix[row][column + 2] * matrix[row][column + 3]);
        }
    }

    // Vertical
    for (int column = 0; column < Size; column++)
    {
        for (int row = 0; row < Size - 3; row++)
        {
            result = max(result, matrix[row][column] * matrix[row + 1][column] * matrix[row + 2][column] * matrix[row + 3][column]);
        }
    }

    // Descending diagonals
    for (int row = 0; row < Size - 3; row++)
    {
        for (int column = 0; column < Size - 3; column++)
        {
            result = max(result, matrix[row][column] * matrix[row + 1][column + 1] * matrix[row + 2][column + 2] * matrix[row + 3][column + 3]);
        }
    }

    // Ascending diagonals
    for (int row = 3; row < Size; row++)
    {
        for (int column = 0; column < Size - 3; column++)
        {
            result = max(result, matrix[row][column] * matrix[row - 1][column + 1] * matrix[row - 2][column + 2] * matrix[row - 3][column + 3]);
        }
    }

    cout << result << endl;

    return 0;
}
