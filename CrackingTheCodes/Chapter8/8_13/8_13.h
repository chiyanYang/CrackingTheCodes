#pragma once
#include "../Ch8Common.h"

# define numOfBox 3

void test8_13();

class stacksOfBox;
class box;

int getTallestStackofBoxes(stacksOfBox* totalBoxs, box* preBox, vector<int>& boxsequences);
bool isValidBoxOn(box* curBox, box* preBox);
void printSequences(vector<int>& boxsequences);

class box
{
public:
	int edge[3]; // 0 for width, 1 for height, 2 for depth
	
	box(int width, int height, int depth)
	{
		edge[0] = width;
		edge[1] = height;
		edge[2] = depth;
	}

	box()
	{
		edge[0] = 0;
		edge[1] = 0;
		edge[2] = 0;
	}
};

class stacksOfBox
{
public:
	box stackBoxs[numOfBox];
	vector<int> usedBox;

	stacksOfBox()
	{
		srand(time(0));  // Initialize random number generator.

		for (int i = 0; i < numOfBox; i++)
		{
			stackBoxs[i].edge[0] = (rand() % 50) + 1;
			stackBoxs[i].edge[1] = (rand() % 50) + 1;
			stackBoxs[i].edge[2] = (rand() % 50) + 1;

			usedBox.push_back(0);
		}
	}

	int getNumOfBox()
	{
		return numOfBox;
	}

	void printBoxs()
	{
		for (int i = 0; i < numOfBox; i++)
		{
			cout << "box" << i << ": ";
			cout << "width = " << stackBoxs[i].edge[0] << " ";
			cout << "height = " << stackBoxs[i].edge[1] << " ";
			cout << "depth = " << stackBoxs[i].edge[2] << " ";
			cout << endl;
		}
	}
};