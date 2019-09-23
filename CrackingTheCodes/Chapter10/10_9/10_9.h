#pragma once
#include "../Ch10Common.h"

void test10_9();

int sortedMatrixSearch(vector<vector<int>>& vMatrix, int target);
int searchRight(vector<vector<int>>& vMatrix, int target, int diagonal);
int searchDown(vector<vector<int>>& vMatrix, int target, int diagonal);