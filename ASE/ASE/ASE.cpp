// ASE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Dictionary.h"
#include <fstream>
#include <string>
#include <unordered_map>
#include <map>
#include <chrono> 

using namespace Containers;
using namespace std;
using namespace std::chrono;

std::string c_inputFile = "C:/Users/elliot/Documents/Github/Uni_ASE/ASE/input-papers-200.txt";

void unorderedMap_list_algorithm()
{
	unordered_map<string, string> map;
	try
	{
		std::ifstream file(c_inputFile);
		if (file.is_open())
		{
			std::string line;
			while (getline(file, line))
			{
				const string s = line.c_str();
				const size_t delimiterIndex = s.find(',');
				map.insert(make_pair(s.substr(0, delimiterIndex), s.substr(delimiterIndex + 1, s.length())));
			}
			file.close();

			list<string> results;
			results.push_back(map.begin()->first);

			//West direciton
			bool found = true;
			while (found)
			{
				std::string s = results.back();
				unordered_map<string, string>::iterator ss = map.find(s);
				if (ss != map.end())
					results.push_back(ss->second);
				else
					found = false;
			}

			//East direction
			found = true;
			while (found)
			{
				found = false;
				for (std::pair<string, string> p : map)
				{
					const string s = results.front();
					if (p.second == s)
					{
						results.push_front(p.first);
						found = true;
					}
				}
			}
		}
	}
	catch (...)
	{
	}	
}

void map_list_algorithm()
{
	map<string, string> map;
	try
	{
		std::ifstream file(c_inputFile);
		if (file.is_open())
		{
			std::string line;
			while (getline(file, line))
			{
				const string s = line.c_str();
				const size_t delimiterIndex = s.find(',');
				map.insert(make_pair(s.substr(0, delimiterIndex), s.substr(delimiterIndex + 1, s.length())));
			}
			file.close();

			list<string> results;
			results.push_back(map.begin()->first);

			//West direciton
			bool found = true;
			while (found)
			{
				std::string s = results.back();
				auto ss = map.find(s);
				if (ss != map.end())
					results.push_back(ss->second);
				else
					found = false;
			}

			//East direction
			found = true;
			while (found)
			{
				found = false;
				for (std::pair<string, string> p : map)
				{
					const string s = results.front();
					if (p.second == s)
					{
						results.push_front(p.first);
						found = true;
					}
				}
			}
		}
	}
	catch (...)
	{
	}
}

void map_unorderedMap_algorithm()
{
	//cant do because unordered
}

void unorderedMap_map_algorithm()
{
	unordered_map<string, string> map;
	try
	{
		std::ifstream file(c_inputFile);
		if (file.is_open())
		{
			std::string line;
			while (getline(file, line))
			{
				const string s = line.c_str();
				const size_t delimiterIndex = s.find(',');
				map.insert(make_pair(s.substr(0, delimiterIndex), s.substr(delimiterIndex + 1, s.length())));
			}
			file.close();

			int valuePosition = map.size();
			std::map<int, string> results;
			results.insert(make_pair(valuePosition, map.begin()->first));

			//East direciton
			bool found = true;
			while (found)
			{
				std::string s = results.rbegin()->second;
				unordered_map<string, string>::iterator ss = map.find(s);
				if (ss != map.end())
					results.insert(make_pair(++valuePosition, ss->second));
				else
					found = false;
			}

			//West direction
			valuePosition = map.size();
			found = true;
			while (found)
			{
				found = false;
				for (std::pair<string, string> p : map)
				{
					const string s = results.begin()->second;
					if (p.second == s)
					{
						results.insert(make_pair(--valuePosition, p.first));
						found = true;
					}
				}
			}
		}
	}
	catch (...)
	{
	}
}

int main()
{
	auto start = high_resolution_clock::now();
	unorderedMap_map_algorithm();
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << duration.count() << endl;

	start = high_resolution_clock::now();
	unorderedMap_list_algorithm();
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << duration.count() << endl;
	
	start = high_resolution_clock::now();
	map_list_algorithm();
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << duration.count() << endl;
	
	
	


	/*
	using Dict = Containers::Dictionary<char, std::pair<int, int>>;

	Dict::Key  key = 'A';
	Dict::Item item = std::pair<int, int>(0, 1);

	Dict dict;
	bool insertSuccess = dict.insert(key, item);
	Dict::Item* itemPtr = dict.lookup(key);
	bool removeSuccess = dict.remove(key);

	return insertSuccess && removeSuccess && itemPtr != nullptr;

	----
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
