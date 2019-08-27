// #include "Chapter1/1_1/1_1.h" // Is Unique
#include "Chapter5/5_3/5_3.h" // Check Permutation


/* Every exercise start in Test function.
 * (1) Includes the header of the exercise, e,g: #include "Chapter1/1_1/1_1.h" // Is Unique
 * (2) Run test_X_X(), e.g: test1_1();
 */
int main()
{
	int toBreak = 0;
	while (true)
	{
		test5_3();
		cout << "To Leave the test, enter 1: " << endl;
		cin >> toBreak;

		if (toBreak == 1)
			break;
	}
	
	return 0;
}