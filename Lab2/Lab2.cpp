// Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BST.h"

int main()
{
	BST testTree = BST();

	testTree.insert(22, "Jane");
	testTree.insert(22, "Mary");
	testTree.insert(0, "Harold");
	testTree.insert(9, "Edward");
	testTree.insert(37, "Victoria");
	testTree.remove();

	const BST::Item* i = testTree.lookup(37);
	std::cout << (i == nullptr) << std::endl;

	//testTree.insert(1, "item");
	//const BST::Item* ii = testTree.lookup(1);

	testTree.insert(22, "Jane");
	testTree.insert(22, "Mary");
	testTree.insert(0, "Harold");
	testTree.insert(9, "Edward");
	testTree.insert(37, "Victoria");
	testTree.insert(4, "Matilda");
	testTree.insert(26, "Oliver");
	testTree.insert(42, "Elizabeth");
	testTree.insert(19, "Henry");
	testTree.insert(4, "Stephen");
	testTree.insert(24, "James");
	testTree.insert(-1, "Edward");
	testTree.insert(31, "Anne");
	testTree.insert(23, "Elizabeth");
	testTree.insert(1, "William");
	testTree.insert(26, "Charles");

	std::cout << testTree;

	testTree.displayTree();
	testTree.remove();
	testTree.displayTree();


	BST t1;
	t1.insert(2, "Will");

	BST t2 = t1;
	t1.insert(22, "Mary");

	std::string* name = t2.lookup(22);
	std::cout << std::endl << (name == nullptr) << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
