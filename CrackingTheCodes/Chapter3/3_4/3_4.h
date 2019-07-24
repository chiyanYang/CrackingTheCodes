#pragma once
#include "../Ch3Common.h"

void test3_4();

template <typename T> class MyQueue;

template <typename T>
void testFunction(MyQueue<T>& myQueue);

template <typename T>
class MyQueue
{
private:
	bool ableToPush;
	int maxQueueSize;
	stack<T> s1; // For Push
	stack<T> s2; // For Pop

public:
	MyQueue(int maxSize)
	{
		ableToPush = true;
		maxQueueSize = maxSize;
	}

	bool push(T data)
	{
		if (this->isFull())
		{
			cout << "Queue is full" << endl;
			return false;
		}

		if (!this->ableToPush)
		{
			revertStack(s2, s1);
			this->ableToPush = true;
		}

		s1.push(data);

		return true;
	}

	T pop()
	{
		if (this->isEmpty())
		{
			cout << "Queue is empty" << endl;
			return NULL;
		}

		if (this->ableToPush)
		{
			revertStack(s1, s2);
			this->ableToPush = false;
		}

		T data = s2.top();
		s2.pop();

		return data;
	}

	// The next(oldest) item in queue
	T& top()
	{
		if (this->isEmpty())
		{
			cout << "Queue is empty" << endl;
			T data = NULL;
			return data;
		}

		if (this->ableToPush)
		{
			revertStack(s1, s2);
			this->ableToPush = false;
		}

		return s2.top();
	}

	bool isEmpty()
	{
		return s1.size() == 0 && s2.size() == 0;
	}

	bool isFull()
	{
		return s1.size() + s2.size() == this->maxQueueSize;
	}

	void printQueue()
	{
		if (this->ableToPush)
		{
			revertStack(s1, s2);
			this->ableToPush = false;
		}

		cout << "Queue: ";

		while (s2.size() != 0)
		{
			T data = s2.top();

			cout << data << " ";
			s1.push(data);
			s2.pop();
		}

		this->ableToPush = true;

		cout << endl << endl;
	}

private:
	void revertStack(stack<T>& src, stack<T>& des)
	{
		while (src.size() != 0)
		{
			des.push(src.top());
			src.pop();
		}
	}
};