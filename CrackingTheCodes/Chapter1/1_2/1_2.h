#pragma once
#include <iostream>
#include <sstream>
#include <ctype.h>
#include <vector>
#include "../../Common.h"

void test1_2();
bool isPermutation(string& s1, string& s2);
void getPermutation(string cur, string sRemain, char chosen, vector<string>& sVector);
string getPermutations(const string& s);