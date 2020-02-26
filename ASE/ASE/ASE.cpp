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

std::string c_inputFile = "C:/input-papers-20.txt";

/*
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
				unordered_map<string, string>::iterator ss = map.find(results.back());
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
					if (p.second == results.front())
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

void unorderedMaps_unorderedMap_algorithm(const string inputFile)
{
	unordered_map<string, string> westMap;
	unordered_map<string, string> eastMap;
	try
	{
		std::ifstream file(inputFile);
		if (file.is_open())
		{
			std::string line;
			while (getline(file, line))
			{
				const string s = line.c_str();
				const size_t delimiterIndex = s.find(',');
				const string leftName = s.substr(0, delimiterIndex);
				const string rightName = s.substr(delimiterIndex + 1, s.length());
				westMap.insert(make_pair(leftName, rightName));
				eastMap.insert(make_pair(rightName, leftName));
			}
			file.close();

			int valuePosition = westMap.size();
			unordered_map<int, string> results;
			results.insert(std::make_pair(valuePosition, westMap.begin()->first));

			//West direciton
			bool found = true;
			while (found)
			{
				auto ss = westMap.find(results.find(valuePosition)->second);
				if (ss != westMap.end())
					results.insert(std::make_pair(++valuePosition, ss->second));
				else
					found = false;
			}

			//East direction
			valuePosition = westMap.size();
			found = true;
			while (found)
			{
				auto ss = eastMap.find(results.find(valuePosition)->second);
				if (ss != eastMap.end())
					results.insert(std::make_pair(--valuePosition, ss->second));
				else
					found = false;
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
				auto ss = map.find(results.back());
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
					if (p.second == results.front())
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


void maps_unorderedMap_algorithm(const string inputFile)
{
	map<string, string> westMap;
	map<string, string> eastMap;
	try
	{
		std::ifstream file(inputFile);
		if (file.is_open())
		{
			std::string line;
			while (getline(file, line))
			{
				const string s = line.c_str();
				const size_t delimiterIndex = s.find(',');
				const string leftName = s.substr(0, delimiterIndex);
				const string rightName = s.substr(delimiterIndex + 1, s.length());
				westMap.insert(make_pair(leftName, rightName));
				eastMap.insert(make_pair(rightName, leftName));
			}
			file.close();

			int valuePosition = westMap.size();
			unordered_map<int, string> results;
			results.insert(std::make_pair(valuePosition, westMap.begin()->first));

			//West direciton
			bool found = true;
			while (found)
			{				
				auto ss = westMap.find(results.find(valuePosition)->second);
				if (ss != westMap.end())
					results.insert(std::make_pair(++valuePosition, ss->second));
				else
					found = false;
			}

			//East direction
			valuePosition = westMap.size();
			found = true;
			while (found)
			{
				auto ss = eastMap.find(results.find(valuePosition)->second);
				if (ss != eastMap.end())
					results.insert(std::make_pair(--valuePosition, ss->second));
				else
					found = false;
			}
		}
	}
	catch (...)
	{
	}
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
				unordered_map<string, string>::iterator ss = map.find(results.rbegin()->second);
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
					if (p.second == results.begin()->second)
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
}*/

void maps_list_algorithm(const string inputFile)
{
	map<string, string> westMap;
	map<string, string> eastMap;
	try
	{
		std::ifstream file(inputFile);
		if (file.is_open())
		{
			std::string line;
			while (getline(file, line))
			{
				const string s = line.c_str();
				const size_t delimiterIndex = s.find(',');
				const string leftName = s.substr(0, delimiterIndex);
				const string rightName = s.substr(delimiterIndex + 1, s.length());
				westMap.insert(make_pair(leftName, rightName));
				eastMap.insert(make_pair(rightName, leftName));
			}
			file.close();

			list<string> results;
			results.push_back(westMap.begin()->first);

			//West direciton
			bool found = true;
			while (found)
			{
				auto ss = westMap.find(results.back());
				if (ss != westMap.end())
					results.push_back(ss->second);
				else
					found = false;
			}

			//East direction
			found = true;
			while (found)
			{
				auto ss = eastMap.find(results.front());
				if (ss != eastMap.end())
					results.push_front(ss->second);
				else
					found = false;
			}
		}
	}
	catch (...)
	{
	}
}

void unorderedMaps_list_algorithm(const string inputFile)
{
	unordered_map<string, string> westMap;
	unordered_map<string, string> eastMap;
	try
	{
		ifstream file(inputFile);
		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				const string s = line.c_str();
				const size_t delimiterIndex = s.find(',');
				const string leftName = s.substr(0, delimiterIndex);
				const string rightName = s.substr(delimiterIndex + 1, s.length());
				westMap.insert(make_pair(leftName, rightName));
				eastMap.insert(make_pair(rightName, leftName));
			}
			file.close();

			list<string> results;
			results.push_back(westMap.begin()->first);

			//West direciton
			bool found = true;
			while (found)
			{
				unordered_map<string, string>::iterator ss = westMap.find(results.back());
				if (ss != westMap.end())
					results.push_back(ss->second);
				else
					found = false;
			}

			//East direction
			found = true;
			while (found)
			{
				unordered_map<string, string>::iterator ss = eastMap.find(results.front());
				if (ss != eastMap.end())
					results.push_front(ss->second);
				else
					found = false;
			}
		}
	}
	catch (...)
	{
	}
}

int main()
{
	//list<string> files = {"1K","2K", "5K", "20K", "50K", "100K", "200K", "500K", "1M", "2M", "3M"};
	//for (string s : files)
	//{
	//	cout << s << endl;
	//	auto start = high_resolution_clock::now();
	//	maps_list_algorithm("C:/input-papers-" + s + ".txt");
	//	auto stop = high_resolution_clock::now();
	//	auto duration = duration_cast<microseconds>(stop - start);
	//	cout << duration.count() << endl;
	//}


	/*
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

	start = high_resolution_clock::now();
	unorderedMaps_list_algorithm();
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << duration.count() << endl;

	maps_list_algorithm();
	
		Timings:

		172876
		141256
		31182

		282643
		286948
		116723

		58154016
		57857447
		61112734

		57133002
		56880218
		60372151

		477649492
		476964182
		717824779
	*/
	
	
	/*using Dict = Containers::Dictionary<char, std::pair<int, int>>;

	Dict::Key  key = 'A';
	Dict::Item item = std::pair<int, int>(0, 1);

	Dict dict;
	bool insertSuccess = dict.insert(key, item);
	Dict::Item* itemPtr = dict.lookup(key);
	bool removeSuccess = dict.remove(key);
	insertSuccess = dict.insert(key, item);
	insertSuccess = dict.insert('B', item);

	Dict dict2 = dict;

	return insertSuccess && removeSuccess && itemPtr != nullptr;*/



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
