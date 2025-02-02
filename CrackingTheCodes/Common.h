#pragma once
#include <string>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include <iostream>
#include <sstream>
#include <ctype.h>
#include <vector>
#include <stack>
#include <queue>        // std::queue
#include <algorithm>    // std::swap
#include <unordered_set>
#include <thread> // For sleep function
#include <chrono> // For sleep function
#include <climits> // for max, min of short,int etc.
#include <list> // std::list
#include <algorithm> // std::find
#include <map> // std::map
#include <bitset>
#include <unordered_map> // std::unordered_map

using namespace std;

int getRandomNum(int min, int max);


template <class T>
void printVector(vector<T>& v)
{
	cout << endl;

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}

	cout << endl;
}