#include "8_2.h"

// Robot in a Grid
void test8_2()
{
	vector<vector<int>> robotMap;
	int row = 9;
	int col = 10;

	initMap(robotMap, row, col);
	robotMap[1][0] = 1;
	robotMap[1][1] = 1;
	robotMap[1][2] = 1;
	robotMap[1][3] = 1;
	robotMap[1][4] = 1;
	robotMap[1][5] = 1;

	robotMap[1][7] = 1;
	robotMap[1][8] = 1;

	robotMap[3][6] = 1;
	robotMap[3][7] = 1;

	print2DVector(robotMap);

	robotInGrid(robotMap, 0, 0);
	printMap(robotMap);
}

void initMap(vector<vector<int>>& robotMap, int col, int row)
{
	robotMap.resize(row);
	for (int i = 0; i < row; ++i)
		robotMap[i].resize(col);

	for (auto& row : robotMap) {
		for (auto& col : row) {
			col = 0;
		}
	}
}

bool robotInGrid(vector<vector<int>>& robotMap, int curRow, int curCol)
{
	if (curCol >= robotMap[0].size() || curRow >= robotMap.size())
	{
		return false;
	}

	if (robotMap[curRow][curCol] == 1 || robotMap[curRow][curCol] == 9) // obstacle or the route does not work before
	{
		return false;
	}

	if (curCol == robotMap[0].size() - 1 && curRow == robotMap.size() - 1)
	{
		robotMap[curRow][curCol] = 2; // End location which is right bottom corner
		return true;
	}

	robotMap[curRow][curCol] = 5;

	if (!robotInGrid(robotMap, curRow, curCol + 1))
	{
		if (!robotInGrid(robotMap, curRow + 1, curCol))
		{
			robotMap[curRow][curCol] = 9;
			return false;
		}
	}
	
	return true;
}
