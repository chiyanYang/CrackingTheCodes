#pragma once
#include "../Ch4Common.h"

void test4_9();

vector<vector<int>> GenerateBSTSequences(TreeNode* rootNode);
vector<vector<int>> mixSequences(vector<vector<int>> leftBSTSequences, vector<vector<int>> rightBSTSequences);
vector<vector<int>> mixSquence(vector<int> leftBSTSequence, vector<int> rightBSTSequence);
vector<vector<int>> addPrefix(vector<vector<int>> totalBSTSequences, int prefix);