// ASE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Dictionary.h"
using namespace Containers;

int main()
{
    std::cout << "Hello World!\n";

	Dictionary<std::string, std::string> dict;
	dict.insert("key1", "item1");
	dict.insert("key2", "item2");
	dict.insert("key3", "item3");

	std::cout << dict.lookup("key2") << std::endl;
	std::cout << dict.remove("key2") << std::endl;
	int x = 0;
	std::cin >> x;
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
