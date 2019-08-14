#include "4_9.h"

// BST Sequences
void test4_9()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9};

	TreeNode* treeRoot = createBinaryTree(v, 0, v.size() - 1);

	vector<vector<int>> totalSequences = GenerateBSTSequences(treeRoot);

	for (auto sequence : totalSequences)
	{
		cout << "Sequence: ";

		for (auto item : sequence)
		{
			cout << item << " ";
		}

		cout << endl;
	}

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

	vector<vector<int>> totalSubBSTSequences = mixSequences(leftBSTSequences, rightBSTSequences);

	if (totalSubBSTSequences.size() == 0)
	{
		vector<int> curSequence{ prefix };
		totalSubBSTSequences.push_back(curSequence);
	}
	else
	{
		totalSubBSTSequences = addPrefix(totalSubBSTSequences, prefix);
	}
	
	return totalSubBSTSequences;
}

vector<vector<int>> mixSequences(vector<vector<int>> leftBSTSequences, vector<vector<int>> rightBSTSequences)
{
	vector<vector<int>> mixedTotalSequences;

	for (auto lsequences : leftBSTSequences)
	{
		for (auto rSequences : rightBSTSequences)
		{
			vector<vector<int>> mixedSequences = mixSquence(lsequences, rSequences);

			for (auto sequence : mixedSequences)
			{
				mixedTotalSequences.push_back(sequence);
			}
		}
	}

	return mixedTotalSequences;
}

vector<vector<int>> mixSquence(vector<int> leftBSTSequence, vector<int> rightBSTSequence)
{
	vector<vector<int>> result;

	if (leftBSTSequence.size() == 0)
	{
		result.push_back(rightBSTSequence);

		return result;
	}
	else if (rightBSTSequence.size() == 0)
	{
		result.push_back(leftBSTSequence);

		return result;
	}

	int prefixLeft = leftBSTSequence.front();
	leftBSTSequence.erase(leftBSTSequence.begin());
	vector<vector<int>> leftMix = mixSquence(leftBSTSequence, rightBSTSequence);
	leftMix = addPrefix(leftMix, prefixLeft);
	leftBSTSequence.insert(leftBSTSequence.begin(), prefixLeft);

	int prefixRight = rightBSTSequence.front();
	rightBSTSequence.erase(rightBSTSequence.begin());
	vector<vector<int>> rightMix = mixSquence(leftBSTSequence, rightBSTSequence);
	rightMix = addPrefix(rightMix, prefixRight);
	rightBSTSequence.insert(rightBSTSequence.begin(), prefixRight);

	for (auto mix : leftMix)
	{
		result.push_back(mix);
	}

	for (auto mix : rightMix)
	{
		result.push_back(mix);
	}

	return result;
}

vector<vector<int>> addPrefix(vector<vector<int>> totalBSTSequences, int prefix)
{
	for (auto& sequences : totalBSTSequences)
	{
		sequences.insert(sequences.begin(), prefix);
	}

	return totalBSTSequences;
}