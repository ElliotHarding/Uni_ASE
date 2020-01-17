#include "pch.h"
#include <iostream>
#include <list>
#include <string>
#include <fstream>

using namespace std;

struct CompareStringPairLeft
{
	bool operator ()(const pair<string, string>& item1, const pair<string, string>& item2)
	{
		return item1.first < item2.first;
	}
};

struct CompareStringPairRight
{
	bool operator ()(const pair<string, string>& item1, const pair<string, string>& item2)
	{
		return item1.second < item2.second;
	}
};

struct CompareIntStringPairRight
{
	bool operator ()(const pair<int, string>& item1, const pair<int, string>& item2)
	{
		return item1.second < item2.second;
	}
};

struct CompareIntStringPairLeft
{
	bool operator ()(const pair<int, string>& item1, const pair<int, string>& item2)
	{
		return item1.second < item2.second;
	}
};

void algorithm(const string inputFile, list<pair<int, string>>& G)
{
	try
	{
		ifstream file(inputFile);
		if (file.is_open())
		{
			list<pair<string, string>> rightSorted;
			list<pair<string, string>> leftSorted;

			string line;
			while (getline(file, line))
			{
				const string s = line.c_str();
				const size_t delimiterIndex = s.find(',');
				const string leftName = s.substr(0, delimiterIndex);
				const string rightName = s.substr(delimiterIndex + 1, s.length());
				rightSorted.push_back(make_pair(leftName, rightName));
				leftSorted.push_back(make_pair(leftName, rightName));	
			}
			file.close();

			rightSorted.sort(CompareStringPairRight());
			leftSorted.sort(CompareStringPairLeft());

			const int N = rightSorted.size()+1;
			
			list<pair<string, string>> F;//List with xi, xi+2 will become F...

			for (pair<string, string> rightPair : rightSorted)
			{
				bool found = false;
				for (pair<string, string> leftPair : leftSorted)
				{
					if (rightPair.second == leftPair.first)
					{
						F.push_back(make_pair(rightPair.first, leftPair.second));
						found = true;
						break;
					}

					//Might put 0 & 1 here into G... //Check map example...
				}

				if (!found)
				{
					G.push_back(make_pair(N - 1, rightPair.first));
					G.push_back(make_pair(N, rightPair.second));
				}
			}

			G.sort(CompareIntStringPairRight());

			list<pair<string, string>> H = F;
			list<pair<string, string>> F_;
			list<pair<int, string>> G_;

			H.sort(CompareStringPairLeft());
			F.sort(CompareStringPairRight());

			int t = 2;
			while (t < N)
			{
				list<pair<string, string>>::iterator fIterator = F.begin();
				list<pair<string, string>>::iterator hIterator = H.begin();
				list<pair<int, string>>::iterator gIterator = G.begin();
				
				while (fIterator != F.end())
				{
					if (fIterator->second == hIterator->first)
					{
						F_.push_back(make_pair(fIterator->first, hIterator->second));
						fIterator++;
						hIterator++;
					}
					else if (gIterator != G.end() && fIterator->second == gIterator->second)
					{
						G_.push_back(make_pair(gIterator->first + t, fIterator->first));
						fIterator++;
						hIterator++;
					}
					else if (fIterator->second > gIterator->second)
					{
						gIterator++;
					}
					else if (fIterator->second > hIterator->first)
					{
						hIterator++;
					}
					//Error?
				}

				G_.sort(CompareIntStringPairRight());
				for (list<pair<int, string>>::iterator i = G_.begin(); i != G_.end(); i++)
				{
					G.push_back(*i);
					G_.remove(*i);
				}

				t *= 2;
				F = F_;
				F_.clear();
			}

			G.sort(CompareIntStringPairLeft());
		}
	}
	catch (...)
	{
	}
}
//C:/input-papers-20.txt
int main()
{
	string fileLocation;
	cin >> fileLocation;

	list<pair<int, string>> results;
	algorithm(fileLocation, results);

	for (pair<int, string> i : results)
	{
		cout << i.second << endl;
	}
}