#include "4_11.h"

// Random Node
void test4_11()
{
	Tree4_11* tree = new Tree4_11();

	tree->insertNode(5);
	tree->insertNode(2);
	tree->insertNode(7);
	tree->insertNode(1);
	tree->insertNode(9);
	tree->insertNode(8);
	tree->insertNode(3);
	tree->insertNode(6);
	tree->insertNode(4);
	tree->printTree();

	tree->deleteNode(7);
	tree->printTree();
	tree->deleteNode(4);
	tree->printTree();
	//tree->deleteNode(5);
	//tree->printTree();
}