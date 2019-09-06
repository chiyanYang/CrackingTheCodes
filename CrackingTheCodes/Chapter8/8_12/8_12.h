#pragma once
#include "../Ch8Common.h"

void test8_12();

class board8x8;
void EightQueens();
void getAllWays(board8x8* queenboard, int curRow);

vector<pair<int, int>> fillNoAccessArea(board8x8* queenboard, int rowIdx, int colIdx);
void removeNoAccessArea(board8x8* queenboard, vector<pair<int, int>>& filledArea);

class board8x8
{
public:
	int board[8][8] = { 0 };

	void printBoard()
	{
		cout << endl;

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] != 9)
				{
					cout << "0" << " ";
				}
				else
				{
					cout << "1" << " ";
				}
			}

			cout << endl;
		}
	}
};