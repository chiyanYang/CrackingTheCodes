#pragma once
#include "../Ch3Common.h"

void test3_1();

template <typename T> class fixStack;

template <typename T>
void callPush(fixStack<T>& myStack, int stackIdx);

template <typename T>
void callPop(fixStack<T>& myStack, int stackIdx);

template <typename T>
void callPeek(fixStack<T>& myStack, int stackIdx);

template <typename T>
void callIsEmpty(fixStack<T>& myStack, int stackIdx);

template <typename T>
void callIsFull(fixStack<T>& myStack, int stackIdx);

template <typename T>
void callPrintStack(fixStack<T>& myStack);

template <typename T> class fixStack;

template <typename T>
class fixStack
{
	int numOfStack;
	T** index;

	struct idx
	{
		int curIdx;
		int length;
	};

	idx states[3];

public:
	fixStack(int length, int stackAmount)
	{
		numOfStack = stackAmount;
		int average = length / numOfStack;
		index = new T*[numOfStack];

		index[0] = new T[length];
		states[0].curIdx = -1;
		states[0].length = average;

		for (int i = 1; i < numOfStack - 1; i++)
		{
			index[i] = index[i - 1] + average + 1;
			states[i].curIdx = -1;
			states[i].length = average;
		}

		index[numOfStack - 1] = index[numOfStack - 2] + average + 1;
		states[numOfStack - 1].curIdx = -1;
		states[numOfStack - 1].length = length - average * (numOfStack - 1);
	}

	bool push(int stackIdx, T data)
	{
		if (stackIdx >= numOfStack || this->isFull(stackIdx))
			return false;

		T* nextSpace;

		nextSpace = index[stackIdx] + states[stackIdx].curIdx + 1;
		*nextSpace = data;
		states[stackIdx].curIdx += 1;
		return true;
	}

	void pop(int stackIdx)
	{
		if (stackIdx >= numOfStack)
			return;

		if (!this->isEmpty(stackIdx))
		{
			states[stackIdx].curIdx--;
		}
	}

	T peek(int stackIdx)
	{
		if (stackIdx >= numOfStack || this->isEmpty(stackIdx))
			return NULL;

		T* curData = index[stackIdx] + states[stackIdx].curIdx;
		return *curData;
	}

	bool isEmpty(int stackIdx)
	{
		if (stackIdx >= numOfStack)
		{
			cout << "Out of range, numOfStack = " << numOfStack << endl;
			return false;
		}

		if (states[stackIdx].curIdx == -1)
			return true;

		return false;
	}

	bool isFull(int stackIdx)
	{
		if (stackIdx >= numOfStack)
		{
			cout << "Out of range, numOfStack = " << numOfStack << endl;
			return false;
		}

		if (states[stackIdx].curIdx == states[stackIdx].length - 1)
			return true;

		return false;
	}

	// For debugging purpose
	void printStack()
	{
		for (int i = 0; i < numOfStack; i++)
		{
			cout << "stack " << i << ": ";

			for (int j = 0; j <= states[i].curIdx; j++)
			{
				cout << " " << *(index[i] + j);
			}

			cout << endl;
		}
	}

	~fixStack()
	{
		free(index[0]);
		free(index);
	}
};