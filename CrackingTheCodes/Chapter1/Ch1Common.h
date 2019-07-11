#pragma once
#include "../Common.h"

string generateTestString(int limitLengrh);
bool is_number(const string& s);
void getPermutation(string cur, string sRemain, char chosen, vector<string>& sVector);
string getPermutations(const string& s);