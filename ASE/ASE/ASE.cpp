// ASE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Dictionary.h"
using namespace Containers;

int main()
{
	using Dict = Containers::Dictionary<char, std::pair<int, int>>;

	Dict::Key  key = 'A';
	Dict::Item item = std::pair<int, int>(0, 1);

	Dict dict;
	bool insertSuccess = dict.insert(key, item);
	Dict::Item* itemPtr = dict.lookup(key);
	bool removeSuccess = dict.remove(key);

	return insertSuccess && removeSuccess && itemPtr != nullptr;

	/*
	std::cout << "Hello World!\n";

	Dictionary<std::string, std::string> dict;
	dict.insert("key1", "item1");
	dict.insert("key2", "item2");
	dict.insert("key3", "item3");

	const char* sss = dict.lookup("key2")->c_str();
	std::cout << sss << std::endl;

	std::cout << dict.remove("key2") << std::endl;

	const char* ssss = dict.lookup("key1")->c_str();
	std::cout << ssss << std::endl;

	const char* sssss = dict.lookup("key3")->c_str();
	std::cout << sssss << std::endl;

	std::function<bool(std::string)> f = [](std::string s) { return s == "key2"; };
	dict.removeIf(f);

	Dictionary<std::string, std::string> dict2 = dict;
	*/
}