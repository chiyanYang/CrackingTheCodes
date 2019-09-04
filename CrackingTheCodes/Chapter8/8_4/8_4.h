#pragma once
#include "../Ch8Common.h"

void test8_4();

void getASubIntSet(vector<int>& intSet, vector<vector<int>>& allSubIntSet, vector<int>& curSubIntSet, int curIdx);
vector<vector<int>> powerSet(vector<int>& intSet);