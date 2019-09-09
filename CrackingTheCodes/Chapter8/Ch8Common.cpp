#include "Ch8Common.h"

void print2DVector(vector<vector<int>>& twoDVector)
{
	for (auto& row : twoDVector) {
		for (auto& col : row) {
			cout << col << " ";
		}
		cout << endl;
	}
	cout << "-------------------" << endl;
	cout << endl;
}

void printVectorString(vector<string> permutations)
{
	cout << endl;

	for (int i = 0; i < permutations.size(); i++)
	{
		cout << permutations[i] << endl;
	}

	cout << endl;
}