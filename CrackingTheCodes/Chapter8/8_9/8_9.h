#pragma once
#include "../Ch8Common.h"

void test8_9();

vector<string> parens(int count);
void getParenthese(vector<string>& combinations, string parenthese, int remainingLeft, int remainingRight);

void printVectorString(vector<string> stringVect);