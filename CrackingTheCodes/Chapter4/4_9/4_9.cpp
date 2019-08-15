#include "4_9.h"

// BST Sequences
void test4_9()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	TreeNode* treeRoot = createBinaryTree(v, 0, v.size() - 1);

	vector<vector<int>> totalSequences = GenerateBSTSequences(treeRoot);

	TreeNode* firstSequenceTree = sequeceToBST(totalSequences[0]);

	for (auto sequence : totalSequences)
	{
		TreeNode* secondSequenceTree = sequeceToBST(sequence);

		bool result = compareTwoTrees(firstSequenceTree, secondSequenceTree);

		freeTree(firstSequenceTree);

		firstSequenceTree = secondSequenceTree;

		cout << "Sequence: ";

		for (auto item : sequence)
		{
			cout << item << " ";
		}

		if (result == false)
		{
			cout << "    ERROR: Not equal to previous!!!";
		}
		else
		{
			cout << "    Same as previous";
		}

		cout << endl;
	}

	freeTree(firstSequenceTree);

	cout << endl;
}

vector<vector<int>> GenerateBSTSequences(TreeNode* rootNode)
{
	if (rootNode == NULL)
	{
		return vector<vector<int>>();
	}

	int prefix = rootNode->getValue();

	vector<vector<int>> leftBSTSequences = GenerateBSTSequences(rootNode->getLeft());
	vector<vector<int>> rightBSTSequences = GenerateBSTSequences(rootNode->getRight());

	vector<vector<int>> totalBSTSequences = mixSequences(leftBSTSequences, rightBSTSequences, prefix);

	return totalBSTSequences;
}

vector<vector<int>> mixSequences(vector<vector<int>>& leftBSTSequences, vector<vector<int>>& rightBSTSequences, int prefix)
{
	vector<vector<int>> mixedTotalSequences;
	vector<int> prefixVec{ prefix };

	if (leftBSTSequences.size() == 0)
	{
		vector<vector<int>> curResult = addPrefix(rightBSTSequences, prefix);

		for (auto& sequences : curResult)
		{
			mixedTotalSequences.push_back(sequences);
		}
	}
	else if (rightBSTSequences.size() == 0)
	{
		vector<vector<int>> curResult = addPrefix(leftBSTSequences, prefix);

		for (auto& sequences : curResult)
		{
			mixedTotalSequences.push_back(sequences);
		}
	}
	else
	{
		for (auto& lsequences : leftBSTSequences)
		{
			for (auto& rSequences : rightBSTSequences)
			{
				mixSequence(lsequences, rSequences, prefixVec, mixedTotalSequences);
			}
		}
	}


	if (mixedTotalSequences.size() == 0)
	{
		mixedTotalSequences.push_back(prefixVec);
	}

	return mixedTotalSequences;
}

void mixSequence(vector<int>& leftBSTSequence, vector<int>& rightBSTSequence, vector<int>& prefixVec, vector<vector<int>>& mixedTotalSequences)
{
	if (leftBSTSequence.size() == 0)
	{
		vector<int> curResult(prefixVec.begin(), prefixVec.end());

		curResult.insert(curResult.end(), rightBSTSequence.begin(), rightBSTSequence.end());

		mixedTotalSequences.push_back(curResult);

		return;
	}
	else if (rightBSTSequence.size() == 0)
	{
		vector<int> curResult(prefixVec.begin(), prefixVec.end());

		curResult.insert(curResult.end(), leftBSTSequence.begin(), leftBSTSequence.end());

		mixedTotalSequences.push_back(curResult);

		return;
	}

	int prefixLeft = leftBSTSequence.front();
	leftBSTSequence.erase(leftBSTSequence.begin());
	prefixVec.push_back(prefixLeft);

	mixSequence(leftBSTSequence, rightBSTSequence, prefixVec, mixedTotalSequences);

	leftBSTSequence.insert(leftBSTSequence.begin(), prefixLeft);
	prefixVec.pop_back();

	int prefixRight = rightBSTSequence.front();
	rightBSTSequence.erase(rightBSTSequence.begin());
	prefixVec.push_back(prefixRight);

	mixSequence(leftBSTSequence, rightBSTSequence, prefixVec, mixedTotalSequences);

	rightBSTSequence.insert(rightBSTSequence.begin(), prefixRight);
	prefixVec.pop_back();
}

TreeNode* sequeceToBST(vector<int>& sequence)
{
	int endOfSequence = sequence.size();
	int curIdx = 0;
	int rootValue = sequence[curIdx];
	curIdx++;

	TreeNode* rootNode = new TreeNode(rootValue);

	while (curIdx < endOfSequence)
	{
		int targetValue = sequence[curIdx];
		int curValue = rootNode->getValue();
		TreeNode* curNode = rootNode;

		while (true)
		{
			if (targetValue < curValue && curNode->getLeft() != NULL)
			{
				curNode = curNode->getLeft();
				curValue = curNode->getValue();
			}
			else if (targetValue < curValue && curNode->getLeft() == NULL)
			{
				TreeNode* targetNode = new TreeNode(targetValue);
				curNode->setLeftNode(targetNode);
				curIdx++;
				break;
			}
			else if (targetValue > curValue && curNode->getRight() != NULL)
			{
				curNode = curNode->getRight();
				curValue = curNode->getValue();
			}
			else if (targetValue > curValue && curNode->getRight() == NULL)
			{
				TreeNode* targetNode = new TreeNode(targetValue);
				curNode->setRightNode(targetNode);
				curIdx++;
				break;
			}
			else
			{
				cout << "ERROR: Sequence cannot have identical value" << endl << endl;
				break;
			}
		}
	}

	return rootNode;
}

bool compareTwoTrees(TreeNode* first, TreeNode* second)
{
	if (first == NULL && second == NULL)
	{
		return true;
	}
	else if (first != NULL && second == NULL)
	{
		return false;
	}
	else if (first == NULL && second != NULL)
	{
		return false;
	}

	if (first->getValue() != second->getValue())
	{
		return false;
	}

	bool resultLeft = compareTwoTrees(first->getLeft(), second->getLeft());
	bool resultRight = compareTwoTrees(first->getRight(), second->getRight());

	return resultLeft && resultRight;
}

vector<vector<int>> addPrefix(vector<vector<int>> totalBSTSequences, int prefix)
{
	for (auto& sequences : totalBSTSequences)
	{
		sequences.insert(sequences.begin(), prefix);
	}

	return totalBSTSequences;
}

