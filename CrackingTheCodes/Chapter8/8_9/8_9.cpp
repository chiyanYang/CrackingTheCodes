#include "8_9.h"

// Parens
void test8_9()
{
	int count = 0;

	cout << "Input the count of Parentheses: ";
	cin >> count;
	cout << endl;

	vector<string> combinations = parens(count);

	printVectorString(combinations);
}

vector<string> parens(int count)
{
	vector<string> combinations;
	getParenthese(combinations, "", count, count);

	return combinations;
}

void getParenthese(vector<string>& combinations, string parenthese, int remainingLeft, int remainingRight)
{
	if (remainingLeft == 0)
	{
		string curParenthese = parenthese;

		for (int i = 0; i < remainingRight; i++)
		{
			curParenthese += ")";
		}
		
		combinations.push_back(curParenthese);

		return;
	}


	if (remainingLeft < remainingRight)
	{
		string curParenthese1 = parenthese;
		curParenthese1 += "(";
		getParenthese(combinations, curParenthese1, remainingLeft - 1, remainingRight);

		string curParenthese2 = parenthese;
		curParenthese2 += ")";
		getParenthese(combinations, curParenthese2, remainingLeft, remainingRight - 1);
	}
	else
	{
		string curParenthese1 = parenthese;
		curParenthese1 += "(";
		getParenthese(combinations, curParenthese1, remainingLeft - 1, remainingRight);
	}
}

void printVectorString(vector<string> stringVect)
{
	cout << endl;

	for (auto& s : stringVect)
	{
		cout << s << endl;
	}

	cout << endl;
}