#pragma once
#include "../Ch3Common.h"

void test3_1();
template <typename T> class fixStack;

template <typename T>
class fixStack
{
	T* index[3];

	struct idx
	{
		int curIdx;
		int length;
	};

	idx states[3];

public:
	fixStack(int length)
	{
		int average = length / 3;
		index[0] = new T[length];
		index[1] = index[0] + average;
		index[2] = index[1] + average;

		states[0].curIdx = 0;
		states[0].length = average;

		states[1].curIdx = 0;
		states[1].length = average;

		states[2].curIdx = 0;
		states[2].length = length - average * 2;
	}

	~fixStack()
	{
		free(index[0]);
	}
};