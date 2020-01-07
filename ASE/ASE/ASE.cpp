// ASE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
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