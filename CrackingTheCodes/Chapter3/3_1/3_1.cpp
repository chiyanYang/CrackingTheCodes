#include "3_1.h"

// Three in One
void test3_1()
{
	int length;

	cout << "Please enter the length the array:";
	cin >> length;
	cout << endl << "The fix size for each stack is \"length / 2\"" << endl;

	fixStack<int> myStack(length);
}

