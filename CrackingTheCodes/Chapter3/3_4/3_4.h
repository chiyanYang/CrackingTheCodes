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
	vector<T> v1;
	vector<T> v2;

public:
	MyQueue() {}

	bool isEmpty()
	{
		return false;
	}

	bool enqueue(T data)
	{
		return true;
	}

	T dequeue()
	{
		return NULL;
	}

	T* front()
	{
		return NULL;
	}

	T* rear()
	{
		return NULL;
	}
};