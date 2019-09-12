#pragma once
#include "../Ch10Common.h"

void test10_1();

void sortedMerge(vector<int>& largeA, int itemCountsInA, vector<int> smallB);
void moveItemToBack(vector<int>& v, size_t itemCountsInA);
void printVectorInt(vector<int>& v);