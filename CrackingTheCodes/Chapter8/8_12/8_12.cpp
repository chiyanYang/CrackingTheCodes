#include "8_12.h"

// Eight Queens
void test8_12()
{
	EightQueens();
}

void EightQueens()
{
	board8x8* queenboard = new board8x8();
	getAllWays(queenboard, 0);

	free(queenboard);
}

void getAllWays(board8x8* queenboard, int curRow)
{
	for (int i = 0; i < 8; i++)
	{
		if (queenboard->board[curRow][i] == 0)
		{
			queenboard->board[curRow][i] = 9;

			if (curRow == 7)
			{
				queenboard->printBoard();
				
			}
			else
			{
				vector<pair<int, int>> filledArea = fillNoAccessArea(queenboard, curRow, i);
				getAllWays(queenboard, curRow + 1);
				removeNoAccessArea(queenboard, filledArea);
			}

			queenboard->board[curRow][i] = 0;
		}
	}
}

vector<pair<int, int>> fillNoAccessArea(board8x8* queenboard, int rowIdx, int colIdx)
{
	vector<pair<int, int>> filledArea;

	// Fill col
	for (int i = rowIdx + 1; i < 8; i++)
	{
		queenboard->board[i][colIdx] = 1;
		filledArea.push_back(make_pair(i, colIdx));
	}

	// Fill diagonal right
	for (int i = rowIdx + 1, j = colIdx + 1; i < 8 && j < 8; i++, j++)
	{
		queenboard->board[i][j] = 1;
		filledArea.push_back(make_pair(i, j));
	}

	// Fill diagonal left
	for (int i = rowIdx + 1, j = colIdx - 1; i < 8 && j >= 0; i++, j--)
	{
		queenboard->board[i][j] = 1;
		filledArea.push_back(make_pair(i, j));
	}

	return filledArea;
}

void removeNoAccessArea(board8x8* queenboard, vector<pair<int, int>>& filledArea)
{
	for (int i = 0; i < filledArea.size(); i++)
	{
		queenboard->board[filledArea[i].first][filledArea[i].second] = 0;
	}
}