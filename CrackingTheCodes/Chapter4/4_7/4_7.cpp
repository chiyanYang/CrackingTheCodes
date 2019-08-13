#include "4_7.h"

// Build Order
void test4_7()
{
	vector<projectDependency> dependencyPro = {
												 projectDependency("a", "d"), 
												 projectDependency("f", "b"),
												 projectDependency("b", "d"),
												 projectDependency("f", "a"),
												 projectDependency("d", "c"),
												 projectDependency("e", "")
											  };

	projectGraph pG(dependencyPro);
	pG.printProjectDependency();

	vector<string> buildOrder = pG.buildProjectOrder();

	for (auto s = buildOrder.begin(); s != buildOrder.end(); ++s)
		std::cout << *s << ' ';
}