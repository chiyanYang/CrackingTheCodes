#include "Ch8Common.h"

void print2DVector(vector<vector<int>>& twoDVector)
{
	for (auto& row : twoDVector) {
		for (auto& col : row) {
			cout << col << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}