#pragma once
#include <string>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()

using namespace std;

string generateTestString(int limitLengrh);
bool is_number(const string& s);