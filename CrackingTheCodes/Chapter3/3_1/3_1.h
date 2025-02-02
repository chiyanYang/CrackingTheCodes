#pragma once
#include "../Ch3Common.h"

void test3_1();

template <typename T> class fixStack;
template <typename T> class variableStack;
template <typename T> class baseStack;
void testFunction(baseStack<int>* myStack);


template <typename T>
void callPush(baseStack<T>* myStack, int stackIdx);

template <typename T>
void callPop(baseStack<T>* myStack, int stackIdx);

template <typename T>
void callPeek(baseStack<T>* myStack, int stackIdx);

template <typename T>
void callIsEmpty(baseStack<T>* myStack, int stackIdx);

template <typename T>
void callIsFull(baseStack<T>* myStack, int stackIdx);

template <typename T>
void callPrintStack(baseStack<T>* myStack);

///////////////////////////////////////////////////////////////////////////////

template <typename T>
class baseStack
{
public:
	int numOfStack;

	virtual bool push(int stackIdx, T data) = 0;
	virtual void pop(int stackIdx) = 0;
	virtual T peek(int stackIdx) = 0;
	virtual bool isEmpty(int stackIdx) = 0;
	virtual bool isFull(int stackIdx) = 0;
	virtual void printStack() = 0;
	virtual ~baseStack() {};

protected:
	bool checkIfIndexOutOfRange(int stackIdx)
	{
		if (stackIdx >= this->numOfStack || stackIdx < 0)
		{
			cout << "Out of range, numOfStack = " << numOfStack << endl;
			return true;
		}

		return false;
	}
};

template <typename T>
class fixStack: public baseStack<T>
{
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

		this->index[this->numOfStack - 1] = this->index[this->numOfStack - 2] + average + 1;
		this->states[this->numOfStack - 1].curIdx = -1;
		this->states[this->numOfStack - 1].length = length - average * (this->numOfStack - 1);
	}

	bool push(int stackIdx, T data)
	{
		if (this->checkIfIndexOutOfRange(stackIdx) || this->isFull(stackIdx))
		{
			cout << "Index Out of Range or is full" << endl;
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
			cout << "Index Out of Range or No Data" << endl;
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
		for (int i = 0; i < this->numOfStack; i++)
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
};

template <typename T>
class variableStack : public baseStack<T>
{
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
		this->stackLength[0] = 0;

		for (int i = 1; i < this->numOfStack; i++)
		{
			this->stackLength[i] = 0;
		}
	}

	bool push(int stackIdx, T data)
	{
		if (this->checkIfIndexOutOfRange(stackIdx) || this->isFull(stackIdx))
		{
			cout << "Index Out of Range or is full" << endl;
			return false;
		}

		if (isRestStackEmptyAndLeftSpace(stackIdx))
		{
			int curIdx = getCurIdx(stackIdx);

			index[curIdx + 1] = data;
			this->stackLength[stackIdx] += 1;
		}
		else
		{
			shiftRest(stackIdx + 1, 0);

			int curIdx = getCurIdx(stackIdx);

			index[curIdx + 1] = data;
			this->stackLength[stackIdx] += 1;
		}

		return true;
	}

	void pop(int stackIdx)
	{
		if (this->checkIfIndexOutOfRange(stackIdx))
			return;

		if (!this->isEmpty(stackIdx))
		{
			shiftRest(stackIdx + 1, 1);
			this->stackLength[stackIdx]--;
		}
	}

	T peek(int stackIdx)
	{
		if (this->checkIfIndexOutOfRange(stackIdx) || this->isEmpty(stackIdx))
		{
			cout << "Index Out of Range or No Data" << endl;
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

		return this->stackLength[stackIdx] == 0;
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
				cout << " " << this->index[j + idx];
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
		return getfilledLength() == this->totalLength;
	}

	int getfilledLength()
	{
		int curLength = 0;

		for (int i = 0; i < this->numOfStack; i++)
		{
			curLength += this->stackLength[i];
		}

		return curLength;
	}

	// Current idx (contains data)
	int getCurIdx(int stackIdx)
	{
		return this->getCurLength(stackIdx) - 1;
	}

	// last idx (contains data)
	int getlastIdx()
	{
		return this->getCurLength(this->numOfStack - 1) - 1;
	}

	int getCurLength(int stackIdx)
	{
		int curLength = 0;

		for (int i = 0; i <= stackIdx; i++)
		{
			curLength += this->stackLength[i];
		}

		return curLength;
	}

	bool isRestStackEmptyAndLeftSpace(int stackIdx)
	{
		if (this->checkIfIndexOutOfRange(stackIdx + 1))
		{
			if (isArrayAllFull())
			{
				return false;
			}

			return true;
		}

		for (int i = stackIdx + 1; i < this->numOfStack; i++)
		{
			if (this->stackLength[i] != 0)
			{
				return false;
			}
		}

		return true;
	}

	// direction: 0 for right shift, 1 for left shift
	void shiftRest(int stackIdx, int direction)
	{
		if (direction == 0)
		{
			for (int i = this->getlastIdx(); i > this->getCurIdx(stackIdx - 1); i--)
			{
				this->index[i + 1] = this->index[i];
			}
		}
		else
		{
			for (int i = this->getCurIdx(stackIdx - 1); i < this->getfilledLength() - 1; i++)
			{
				this->index[i] = this->index[i + 1];
			}
		}
	}
};