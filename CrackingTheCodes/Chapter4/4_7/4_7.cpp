#include "4_7.h"

// Build Order
void test4_7()
{
	vector<projectDependency> dependencyPro = {
												 projectDependency("a", "c"), 
												 projectDependency("b", "c"),
												 projectDependency("c", "a"),
												 projectDependency("d", "e"),
												 projectDependency("e", "g"),
												 projectDependency("f", "g"),
												 projectDependency("g", "h"),
												 projectDependency("h", "i"),
											  };

	projectGraph pG(dependencyPro);
	pG.printProjectDependency();
}