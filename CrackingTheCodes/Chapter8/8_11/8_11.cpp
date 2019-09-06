#include "8_11.h"

// Coins
void test8_11()
{
	int target = 0;

	cout << "Enter the target: ";
	cin >> target;
	cout << endl;

	vector<vector<int>> ways;
	int result = coins(target, ways);

	cout << "Result = " << result << endl;
	printVectorInt(ways);
}

int coins(int target, vector<vector<int>>& ways)
{
	int currency[3] = { 25, 10, 5 };
	vector<int> way;

	return getCoins(ways, way, currency, 0, 0, target);
}

int getCoins(vector<vector<int>>& ways, vector<int> way, int currency[3], int curCurrencyIdx, int curMoney, int target)
{
	if (curCurrencyIdx == 4 || curMoney > target)
	{
		return 0;
	}

	if (curMoney == target)
	{
		ways.push_back(way);
		return 1;
	}

	int result = 0;
	int addedMoney = currency[curCurrencyIdx];
	while (target >= curMoney)
	{
		result += getCoins(ways, way, currency, curCurrencyIdx + 1, curMoney, target);
		curMoney += addedMoney;
		way.push_back(addedMoney);
	}

	return result;
}

void printVectorInt(vector<vector<int>>& ways)
{
	cout << endl;

	for (int i = 0; i < ways.size(); i++)
	{
		for (int j = 0; j < ways[i].size(); j++)
		{
			cout << ways[i][j] << " ";
		}

		cout << endl;
	}

	cout << endl;
}