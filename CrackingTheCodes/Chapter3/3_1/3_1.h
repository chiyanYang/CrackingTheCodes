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

	idx* states;

public:
	fixStack(int length, int stackAmount)
	{
		this->numOfStack = stackAmount;
		int average = length / this->numOfStack;
		this->index = new T*[this->numOfStack];
		this->states = new idx[this->numOfStack];

		this->index[0] = new T[length];
		this->states[0].curIdx = -1;
		this->states[0].length = average;

		for (int i = 1; i < this->numOfStack - 1; i++)
		{
			this->index[i] = index[i - 1] + average + 1;
			this->states[i].curIdx = -1;
			this->states[i].length = average;
		}

		this->index[numOfStack - 1] = this->index[numOfStack - 2] + average + 1;
		this->states[numOfStack - 1].curIdx = -1;
		this->states[numOfStack - 1].length = length - average * (this->numOfStack - 1);
	}

	bool push(int stackIdx, T data)
	{
		if (this->checkIfIndexOutOfRange(stackIdx) || this->isFull(stackIdx))
		{
			return false;
		}

		T* nextSpace;

		nextSpace = this->index[stackIdx] + this->states[stackIdx].curIdx + 1;
		*nextSpace = data;
		this->states[stackIdx].curIdx += 1;

		return true;
	}

	void pop(int stackIdx)
	{
		if (this->checkIfIndexOutOfRange(stackIdx))
		{
			return;
		}

		if (!this->isEmpty(stackIdx))
		{
			this->states[stackIdx].curIdx--;
		}
	}

	T peek(int stackIdx)
	{
		if (this->checkIfIndexOutOfRange(stackIdx) || this->isEmpty(stackIdx))
		{
			return NULL;
		}

		T* curData = this->index[stackIdx] + this->states[stackIdx].curIdx;
		return *curData;
	}

	bool isEmpty(int stackIdx)
	{
		if (this->checkIfIndexOutOfRange(stackIdx))
		{
			return false;
		}

		return this->states[stackIdx].curIdx == -1;
	}

	bool isFull(int stackIdx)
	{
		if (this->checkIfIndexOutOfRange(stackIdx))
		{
			return false;
		}

		return this->states[stackIdx].curIdx == states[stackIdx].length - 1;
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
		free(states);
	}

private:
	bool checkIfIndexOutOfRange(int stackIdx)
	{
		if (stackIdx >= this->numOfStack)
		{
			cout << "Out of range, numOfStack = " << numOfStack << endl;
			return true;
		}

		return false;
	}
};

template <typename T>
class variableStack
{
	int numOfStack;
	int totalLength;
	T* index;
	int* stackLength;

public:
	variableStack(int length, int stackAmount)
	{
		this->totalLength = length;
		this->numOfStack = stackAmount;
		this->stackLength = new int[this->numOfStack];

		// All the stacks' lengths should be zero at the beginning
		this->index = new T[this->totalLength];
		this->stackLength[0].length = 0;

		for (int i = 1; i < this->numOfStack; i++)
		{
			this->index[i] = this->index[i - 1];
			this->stackLength[i].length = 0;
		}
	}

	bool push(int stackIdx, T data)
	{
		if (this->checkIfIndexOutOfRange(stackIdx) || this->isFull(stackIdx))
			return false;

		// Todo

		return true;
	}

	void pop(int stackIdx)
	{
		if (this->checkIfIndexOutOfRange(stackIdx))
			return;

		if (!this->isEmpty(stackIdx))
		{
			// Todo
		}
	}

	T peek(int stackIdx)
	{
		if (this->checkIfIndexOutOfRange(stackIdx) || this->isEmpty(stackIdx))
		{
			return NULL;
		}

		int curIdx = this->getCurIdx(stackIdx);

		T* curData = this->index + curIdx;
		return *curData;
	}

	bool isEmpty(int stackIdx)
	{
		if (this->checkIfIndexOutOfRange(stackIdx))
		{
			return false;
		}

		return this->stackLength[stackIdx].length == -1;
	}

	bool isFull(int stackIdx)
	{
		if (this->checkIfIndexOutOfRange(stackIdx))
		{
			return false;
		}

		return this->isArrayAllFull();
	}

	// For debugging purpose
	void printStack()
	{
		int idx = 0;

		for (int i = 0; i < this->numOfStack; i++)
		{
			cout << "stack " << i << ": ";

			for (int j = 0; j <= this->stackLength[i] - 1; j++)
			{
				cout << " " << *(this->index[j + idx]);
			}

			idx += this->stackLength[i];

			cout << endl;
		}
	}

	~variableStack()
	{
		free(this->index);
		free(this->stackLength);
	}

private:
	bool isArrayAllFull()
	{
		int curLength = 0;

		for (int i = 0; i < this->numOfStack; i++)
		{
			curLength += this->stackLength[i].length;
		}

		return curLength == this->totalLength;
	}

	int getCurIdx(int stackIdx)
	{
		return this->getCurLength(stackIdx) - 1;
	}

	int getCurLength(int stackIdx)
	{
		int curLength = 0;

		for (int i = 0; i < this->numOfStack; i++)
		{
			curLength += this->stackLength[i].length;
		}

		return curLength;
	}

	bool checkIfIndexOutOfRange(int stackIdx)
	{
		if (stackIdx >= this->numOfStack)
		{
			cout << "Out of range, numOfStack = " << numOfStack << endl;
			return true;
		}

		return false;
	}
};