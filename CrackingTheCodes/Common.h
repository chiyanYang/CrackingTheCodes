#pragma once
#include <string>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include <iostream>
#include <sstream>
#include <ctype.h>
#include <vector>
#include <algorithm>    // std::swap

using namespace std;

string generateTestString(int limitLengrh);
bool is_number(const string& s);