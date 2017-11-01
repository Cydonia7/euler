#include "triangleSum.h"

using namespace std;

int maximumPathSum(vector<vector<int> > triangle)
{
    for (int row = triangle.size() - 2; row >= 0; row--)
    {
        for (int column = 0; column < triangle[row].size(); column++)
        {
            // Add the maximum of the cells below to the current cell
            triangle[row][column] += max(triangle[row + 1][column], triangle[row + 1][column + 1]);
        }
    }

    return triangle[0][0];
}
