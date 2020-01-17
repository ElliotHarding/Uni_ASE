#include "pch.h"
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <fstream>
using namespace std;

void map_list_algorithm(const string c_inputFile, list<string>& results)
{
	map<string, string> map;
	try
	{
		ifstream file(c_inputFile);
		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				const string s = line.c_str();
				const size_t delimiterIndex = s.find(',');
				map.insert(make_pair(s.substr(0, delimiterIndex), s.substr(delimiterIndex + 1, s.length())));
			}
			file.close();

			//Start with arbiturary 
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
				for (pair<string, string> p : map)
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

int main()
{
	string fileLocation;
	cin >> fileLocation;

	list<string> results;
	map_list_algorithm(fileLocation, results);

	for (string s : results)
	{
		std::cout << s << std::endl;
	}
}