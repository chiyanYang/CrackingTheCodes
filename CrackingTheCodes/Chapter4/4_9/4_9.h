#pragma once
#include "../Ch4Common.h"

void test4_9();

vector<vector<int>> GenerateBSTSequences(TreeNode* rootNode);
vector<vector<int>> mixSequences(vector<vector<int>>& leftBSTSequences, vector<vector<int>>& rightBSTSequences, int prefix);
void mixSequence(vector<int>& leftBSTSequence, 
				 vector<int>& rightBSTSequence, 
				 vector<int>& prefix, 
				 vector<vector<int>>& mixedTotalSequences);

TreeNode* sequeceToBST(vector<int>& sequence);
bool compareTwoTrees(TreeNode* first, TreeNode* second);

vector<vector<int>> addPrefix(vector<vector<int>> totalBSTSequences, int prefix);