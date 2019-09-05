#include "8_6.h"

// Towers of Hanoi
void test8_6()
{
	stack<int> towers[3];
	fillDestinationTower(towers[0], 5);
	printTotwers(towers);

	towersOfHanoi(towers, 0, 2, 1);
}

void towersOfHanoi(stack<int> towers[3], int source, int des, int middle)
{
	if (towers[source].size() == 0 && towers[middle].size() == 0)
	{
		return;
	}

	moveHanoi(towers, towers[source].size(), 0, 2, 1);
}

void moveHanoi(stack<int> towers[3], int stackCountToMove, int source, int des, int middle)
{
	if (stackCountToMove == 0)
	{
		return;
	}

	int curStackCountToMove = stackCountToMove - 1;

	moveHanoi(towers, curStackCountToMove, source, middle, des);

	int value = towers[source].top();
	towers[source].pop();
	towers[des].push(value);

	printTotwers(towers);

	moveHanoi(towers, curStackCountToMove, middle, des, source);
}

void fillDestinationTower(stack<int>& tower, int num)
{
	for (int i = num; i >= 1; i--)
	{
		tower.push(i);
	}
}

void printTotwers(stack<int> towers[3])
{
	cout << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << i << ": ";

		stack<int> copied = towers[i];
		int stackSize = copied.size();
		for (int j = 0; j < stackSize; j++)
		{
			cout << copied.top() << " ";
			copied.pop();
		}

		cout << endl;
	}

	cout << endl;
}