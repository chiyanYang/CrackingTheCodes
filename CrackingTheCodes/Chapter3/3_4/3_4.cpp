#include "3_4.h"

// Queue via Stacks
void test3_4()
{
	int length;
	cout << "Enter the max length of Queue: ";
	cin >> length;
	cout << endl;

	MyQueue<int> myQueue(length);
	testFunction(myQueue);
}

template <typename T>
void testFunction(MyQueue<T>& myQueue)
{
	while (true)
	{
		int method;

		cout << "method 1: callPush" << endl;
		cout << "method 2: callPop" << endl;
		cout << "method 3: callTop" << endl;
		cout << "method 4: callIsEmpty" << endl;
		cout << "method 5: callIsFull" << endl;
		cout << "method 6: callPrintStack" << endl;
		cout << "---------------------" << endl;
		cout << "Enter the mothod to execute: ";
		cin >> method;
		cout << endl;

		int index = 0;
		T data = NULL;
		bool result = false;

		switch (method)
		{
			case 1: cout << "Enter the data: ";
					cin >> data;
					cout << endl;
					result = myQueue.push(data);
					cout << "Push data result: " << result << endl << endl;
					break;
			case 2: myQueue.pop();
					cout << "Pop done" << endl << endl;
					break;
			case 3: data = myQueue.top();
					cout << "Data = " << data << endl << endl;
					break;
			case 4: result = myQueue.isEmpty();
					cout << "Is empty: " << result << endl << endl;
					break;
			case 5: result = myQueue.isFull();
					cout << "Is full: " << result << endl << endl;
					break;
			case 6: myQueue.printQueue();
					break;
		default: cout << "No Method found" << endl;
		}
	}
}