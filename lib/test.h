#pragma once

#include <iostream>
#include <vector>
#include <string>

#define BEGIN_TEST() testResults results = {};
#define END_TEST() printResults(results);
#define ASSERT_EQUALS(X, Y) { auto x = X; auto y = Y; assert(results, #X" should be equal to "#Y", got " + prettyPrint(x), x == y); }
#define ASSERT_NOT_EQUALS(X, Y) { auto x = X; auto y = Y; assert(results, #X" should not be equal to "#Y", got " + prettyPrint(x), x != y); }

typedef struct {
    int failed;
    int total;
    std::vector<std::string> errors;
} testResults;

void printResults(testResults results)
{
    std::cout << (results.failed > 0 ? "\x1b[31m" : "\x1b[32m");
    std::cout << results.total << " executed, " << results.failed << " failed\x1b[0m" << std::endl;

    for (std::string error : results.errors) {
        std::cout << "  - " << error << std::endl;
    }
}

void assert(testResults &results, std::string message, bool condition)
{
    results.total++;

    if (!condition) {
        results.failed++;
        results.errors.push_back(message);
    }
}

std::string prettyPrint(std::string s)
{
    return '"' + s + '"';
}

