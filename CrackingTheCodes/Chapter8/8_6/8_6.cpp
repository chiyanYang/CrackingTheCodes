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

	int value = towers[source].top();
	towers[source].pop();

	towers[middle].push(value);

	towersOfHanoi(towers, source, int des, int middle)

}

void fillDestinationTower(stack<int>& tower, int num)
{
	for (int i = num; i >= 0; i--)
	{
		tower.push(i);
	}
}

void printTotwers(stack<int> towers[3])
{
	cout << endl;

	for (int i = 0; i < 3; i++)
	{
		stack<int> copied = towers[i];
		for (int j = 0; j < copied.size; j++)
		{
			cout << copied.top() << " ";
			copied.pop();
		}

		cout << endl;
	}

	cout << endl;
}