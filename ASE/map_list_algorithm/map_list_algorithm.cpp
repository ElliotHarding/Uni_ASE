#include "pch.h"
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <fstream>
using namespace std;

void map_list_algorithm(const string c_inputFile, list<string>& results)
{
	map<string, string> westMap;
	map<string, string> eastMap;
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
				const string leftName = s.substr(0, delimiterIndex);
				const string rightName = s.substr(delimiterIndex + 1, s.length());
				westMap.insert(make_pair(leftName, rightName));
				eastMap.insert(make_pair(rightName, leftName));
			}
			file.close();

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