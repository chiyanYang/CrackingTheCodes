#pragma once
#include "../Ch8Common.h"

void test8_11();

int coins(int target, vector<vector<int>>& ways);
int getCoins(vector<vector<int>>& ways, vector<int> way, int currency[3], int curCurrencyIdx, int curMoney, int target);

void printVectorInt(vector<vector<int>>& ways);