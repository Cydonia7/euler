#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>

std::vector<int> readNumbersLine(const std::string &line);
std::vector<std::vector<int> > readNumbersMatrix(const std::string &filename);
