#include "3_2.h"

// Stack Min
void test3_2()
{
	stackWithMin<int> myStack;
	testFunction(myStack);
}

template <typename T>
void testFunction(stackWithMin<T>& myStack)
{
	while (true)
	{
		int method;

		cout << "method 1: callPush" << endl;
		cout << "method 2: callPop" << endl;
		cout << "method 3: callPeek" << endl;
		cout << "method 4: callIsEmpty" << endl;
		cout << "method 5: callIsFull" << endl;
		cout << "method 6: callMin" << endl;
		cout << "method 7: callPrintStack" << endl;
		cout << "---------------------" << endl;
		cout << "Enter the mothod to execute: ";
		cin >> method;
		cout << endl;

		T data = NULL;
		bool result = false;

		switch (method)
		{
			case 1: cout << "Enter the data: ";
					cin >> data;
					cout << endl;
					result = myStack.push(data);
					cout << "Push data result: " << result << endl;
					break;
			case 2: myStack.pop();
					cout << "Pop done" << endl;
					break;
			case 3: data = myStack.peek();
					cout << "Data = " << data << endl;
					break;
			case 4: result = myStack.isEmpty();
					cout << "Is empty: " << result << endl;
					break;
			case 5: result = myStack.isFull();
					cout << "Is full: " << result << endl;
					break;
			case 6: data = myStack.min();
					cout << "Min: " << data << endl;
					break;
			case 7: myStack.printStack();
					break;
			default: cout << "No Method found" << endl;
		}
	}
}