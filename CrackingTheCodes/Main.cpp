// #include "Chapter1/1_1/1_1.h" // Is Unique
#include "Chapter8/8_5/8_5.h"


/* Every exercise start in Test function.
 * (1) Includes the header of the exercise, e,g: #include "Chapter1/1_1/1_1.h" // Is Unique
 * (2) Run test_X_X(), e.g: test1_1();
 */
int main()
{
	int toBreak = 0;
	while (true)
	{
		test8_5();
		cout << "To Leave the test, enter 1: " << endl;
		cin >> toBreak;

		if (toBreak == 1)
			break;
	}
	
	return 0;
}