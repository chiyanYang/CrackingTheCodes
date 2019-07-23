#pragma once
#include "../Ch3Common.h"

void test3_3();

template <typename T> class SetOfStacks;

template <typename T>
void testFunction(SetOfStacks<T>& myStack);

template <typename T>
class SetOfStacks
{
private:
	int vectorMaxSize;
	vector<vector<T>> vSet;

public:
	SetOfStacks(int perVecSize)
	{
		this->vectorMaxSize = perVecSize;
	}

	bool push(T data)
	{
		if (this->isFull())
		{
			cout << "Stack is full" << endl;
			return false;
		}

		bool isNotFullInInnerStack = false;
		int index = -1;
		for (auto itV = vSet.cbegin(); itV != vSet.cend(); ++itV)
		{
			index++;
			if (itV->size() != this->vectorMaxSize)
			{
				isNotFullInInnerStack = true;
				break;
			}
		}

		if (isNotFullInInnerStack == false && (vSet.size() == 0 || vSet.back().size() == this->vectorMaxSize))
		{
			vector<T> v;
			vSet.push_back(v);
			vSet.back().push_back(data);
		}
		else if (isNotFullInInnerStack == true)
		{
			vSet[index].push_back(data);
		}
		else
		{
			vSet.back().push_back(data);
		}

		return true;
	}

	void pop()
	{
		if (this->isEmpty())
		{
			cout << "No data inside" << endl;
			return;
		}

		if (vSet.back().size() == 1)
		{
			vSet.erase(vSet.end() - 1);
		}
		else
		{
			vector<T>& v = vSet.back();
			v.erase(v.end() - 1);
		}
	}

	void popAt(int index)
	{
		if (index >= vSet.size() || vSet[index].size() == 0)
		{
			cout << "No data inside" << endl;
			return;
		}

		vSet[index].erase(vSet[index].end() - 1);
	}

	T peek()
	{
		if (this->isEmpty())
		{
			cout << "No data inside" << endl;
			return NULL;
		}

		return vSet.back().back();
	}

	bool isEmpty()
	{
		if (vSet.size() == 0)
		{
			return true;
		}

		return false;
	}

	bool isFull()
	{
		return false;
	}

	void printStack()
	{
		int count = vSet.size();
		for (auto ritV = vSet.crbegin(); ritV != vSet.crend(); ++ritV)
		{
			cout << "Stack " << count << ": " << endl;
			for (auto rit = ritV->crbegin(); rit != ritV->crend(); ++rit)
			{
				cout << *rit << " ";
			}
			count--;
			cout << endl;
		}
	}

	~SetOfStacks() {};
};