#include "io.h"

using namespace std;

vector<int> readNumbersLine(const string &line)
{
    stringstream stream(line);
    vector<int> values((istream_iterator<int>(stream)), (istream_iterator<int>()));

    return values;
}

vector<vector<int> > readNumbersMatrix(const string &filename)
{
    ifstream file(filename);
    string line;
    vector<vector<int> > triangle;

    while (getline(file, line)) {
        triangle.push_back(readNumbersLine(line));
    }

    return triangle;
}
