#pragma once
#include "../Ch4Common.h"

void test4_12();

int Bruth_And_Forced_GetTotalPathsWithSum(TreeNode* rootNode, int targetSum);
int Bruth_And_Forced_GetTotalPathsWithSumInCurNode(TreeNode* rootNode, int targetSum);
void preOrderTraversal(TreeNode* rootNode, int& totalCount, int& curSum, int targetSum);

