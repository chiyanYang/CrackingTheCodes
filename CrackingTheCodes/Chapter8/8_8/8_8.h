#pragma once
#include "../Ch8Common.h"

void test8_8();

void getPermutation(vector<string>& permutations, map<char, int>& charCountMap, int length, string prefix);
vector<string> permutationsWithDups(string dupChars);
void buildMapOfCharCount(map<char, int>& charCountMap, string dupChars);