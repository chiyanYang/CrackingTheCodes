#include "4_7.h"

// Build Order
void test4_7()
{
	vector<projectDependency> dependencyPro = {
												 projectDependency("a", "e"), 
												 projectDependency("f", "b"),
												 projectDependency("b", "d"),
												 projectDependency("f", "a"),
												 projectDependency("d", "c"),
												 projectDependency("e", "")
											  };

	projectGraph pG(dependencyPro);
	pG.printProjectDependency();
	
	int method = 0;
	cout << "Enter the method to call: ";

	cin >> method;

	cout << endl;
	
	if (method == 0)
	{
		vector<string> buildOrder = pG.buildProjectOrder();

		if (buildOrder.size() == 0)
		{
			cout << "Loop detected" << endl;
		}
		else
		{
			for (auto s = buildOrder.begin(); s != buildOrder.end(); ++s)
				std::cout << *s << ' ';
		}

		cout << endl << endl;
	}
	else
	{
		stack<string> buildOrder = pG.buildProjectOrderRecursive();

		if (buildOrder.size() == 0)
		{
			cout << "Loop detected" << endl;
		}
		else
		{
			while (buildOrder.size() != 0)
			{
				cout << buildOrder.top() << ' ';
				buildOrder.pop();
			}
		}

		cout << endl << endl;
	}
}