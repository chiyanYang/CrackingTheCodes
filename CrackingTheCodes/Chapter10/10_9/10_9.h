#pragma once
#include "../Ch10Common.h"

void test10_9();

struct coordinate
{
	int row;
	int col;
};

coordinate sortedMatrixSearch(vector<vector<int>>& vMatrix, coordinate begin, coordinate end, int target);

bool isValidSquare(coordinate coordBegin, coordinate coordEnd);
coordinate getMiddle(coordinate coordBegin, coordinate coordEnd);
int getValue(vector<vector<int>>& vMatrix, coordinate coordCur);

