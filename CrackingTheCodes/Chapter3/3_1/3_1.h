#pragma once
#include "../Ch3Common.h"

void test3_1();
template <typename T> class fixStack;

template <typename T>
class fixStack
{
	const int numOfStack = 3;
	T* index[numOfStack];

	struct idx
	{
		int curIdx;
		int length;
	};

	idx states[3];

public:
	fixStack(int length)
	{
		int average = length / numOfStack;
		
		index[0] = new T[length];
		states[0].curIdx = -1;
		states[0].length = average;

		for (int i = 1; i < numOfStack - 1; i++)
		{
			index[i] = index[i - 1] + average;
			states[i].curIdx = -1;
			states[i].length = average;
		}

		index[numOfStack - 1] = index[numOfStack - 2] + average;
		states[numOfStack - 1].curIdx = -1;
		states[numOfStack - 1].length = length - average * 2;
	}

	bool push(int stackIdx, T data)
	{
		if (stackIdx >= numOfStack)
			return;

		T* nextSpace;

		if (!this.isFull(stackIdx))
		{
			nextSpace = index[stackIdx] + states[stackIdx].curIdx + 1;
			*nextSpace = data;
			states[stackIdx].curIdx += 1;
			return true;
		}

		return false;
	}

	void pop(int stackIdx)
	{
		if (stackIdx >= numOfStack)
			return;

		if (!this.isEmpty(stackIdx))
		{
			states[stackIdx].curIdx--;
		}
	}

	T peek(int stackIdx)
	{
		if (stackIdx >= numOfStack)
			return;

		if (!this.isEmpty(stackIdx))
		{
			states[stackIdx].curIdx--;
			T* curData = index[stackIdx] + states[stackIdx].curIdx;
			return *curData;
		}

		return NULL;
	}

	bool isEmpty(int stackIdx)
	{
		if (states[stackIdx].curIdx == -1)
			return true;

		return false;
	}

	bool isFull(int stackIdx)
	{
		if (states[stackIdx].curIdx == states[stackIdx].length - 1)
			return true;

		return false;
	}

	~fixStack()
	{
		free(index[0]);
	}
};