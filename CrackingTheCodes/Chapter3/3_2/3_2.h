#pragma once
#include "../Ch3Common.h"

void test3_2();

template <typename T> class stackWithMin;

template <typename T>
void testFunction(stackWithMin<T>& myStack);

template <typename T>
class stackWithMin
{
private:
	const int vectorMaxSize = 100;
	vector<T> v;
	vector<T> minV;

public:
	bool push(T data)
	{
		if (isFull())
		{
			cout << "Stack is full" << endl;
			return false;
		}

		v.push_back(data);

		if (minV.size() != 0 && this->min() < data)
		{
			minV.push_back(min());
		} 
		else
		{
			minV.push_back(data);
		}
		return true;
	}

	void pop()
	{
		if (this->isEmpty())
		{
			return;
		}

		v.erase(v.end() - 1);

		minV.erase(minV.end() - 1);
	}

	T peek()
	{
		if (this->isEmpty())
		{
			cout << "No data inside" << endl;
			return NULL;
		}

		return v.back();
	}

	T min()
	{
		if (minV.size() == 0)
		{
			cout << "No data inside" << endl;
		}

		return minV.back();
	}

	bool isEmpty()
	{
		return v.size() == 0;
	}

	bool isFull()
	{
		return v.size() == vectorMaxSize;
	}

	void printStack()
	{
		for (auto rit = v.crbegin(); rit != v.crend(); ++rit)
		{
			cout << *rit << " ";
		}
		cout << endl;
	}

	~stackWithMin() {};
};
