#include "Common.h"

int getRandomNum(int min, int max)
{
	/* initialize random seed: */
	srand(time(NULL));

	/* generate secret number between min and max: */
	int randomNum = rand() % max + min;

	return randomNum;
}