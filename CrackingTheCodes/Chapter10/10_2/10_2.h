#pragma once
#include "../Ch10Common.h"

void test10_2();

void groupAnagrams(vector<string>& stringVec);
bool compareAnagrams(string s1, string s2);
void sortString(string& s);

vector<string> groupAnagramsByHash(vector<string>& stringVec);
int calculateScore(string& s);

void printVecString(vector<string> sVec);