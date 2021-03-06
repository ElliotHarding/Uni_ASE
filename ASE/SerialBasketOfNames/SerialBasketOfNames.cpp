#include "pch.h"
#include <iostream>
#include <list>
#include <string>
#include <fstream>

using namespace std;

template<typename left, typename right> 
struct ComparePairLeft
{
	bool operator ()(const pair<left, right>& item1, const pair<left, right>& item2)
	{
		return item1.first < item2.first;
	}
};

template<typename left, typename right>
struct ComparePairRight
{
	bool operator ()(const pair<left, right>& item1, const pair<left, right>& item2)
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

			rightSorted.sort(ComparePairRight<string, string>());
			leftSorted.sort(ComparePairLeft<string,string>());

			const int N = rightSorted.size()+1;
			
			list<pair<string, string>> F;//List with xi, xi+2 will become F...		
			list<pair<string, string>>::iterator rIterator = rightSorted.begin();
			list<pair<string, string>>::iterator lIterator = leftSorted.begin();

			while (lIterator != leftSorted.end() && rIterator != rightSorted.end())
			{
				if (lIterator->first == rIterator->second)
					F.push_back(std::make_pair(rIterator->first, lIterator->second));
				else
				{
					lIterator++;
					if (lIterator->first == rIterator->second)
						F.push_back(std::make_pair(rIterator->first, lIterator->second ));
					else
					{
						lIterator--;
						G.push_back(std::make_pair(N - 1, rIterator->first));
						G.push_back(std::make_pair(N, rIterator->second));
						rIterator++;
						if (lIterator->first == rIterator->second)
							F.push_back(std::make_pair(rIterator->first, lIterator->second));
					}
				}
				lIterator++;
				rIterator++;
			}


			list<pair<string, string>> F_, H;
			list<pair<int, string>> G_;			
			int t = 2;
			while (t < N)
			{
				H = F;
				H.sort(ComparePairLeft<string, string>());
				F.sort(ComparePairRight<string, string>());
				G.sort(ComparePairRight<int, string>());

				list<pair<string, string>>::iterator fIterator = F.begin();
				list<pair<string, string>>::iterator hIterator = H.begin();
				list<pair<int, string>>::iterator gIterator = G.begin();
				
				while (fIterator != F.end())
				{
					if (hIterator!= H.end() && fIterator->second == hIterator->first)
					{
						F_.push_back(make_pair(fIterator->first, hIterator->second));
						fIterator++;
						hIterator++;
					}
					else if (gIterator!=G.end() && fIterator->second == gIterator->second)
					{
						G_.push_back(make_pair(gIterator->first - t, fIterator->first));
						fIterator++;
						gIterator++;							
					}
					else if (gIterator != G.end() && fIterator->second > gIterator->second)
					{
						gIterator++;							
					}
					else if (fIterator->second > hIterator->first)
					{
						hIterator++;
					}
				}

				G_.sort(ComparePairRight<int,string>());
				while (!G_.empty())
				{
					G.push_back(*G_.begin());
					G_.pop_front();
				}

				t *= 2;
				F = F_;
				F_.clear();
			}

			G.sort(ComparePairLeft<int,string>());
		}
	}
	catch (...)
	{
	}
}


//#include <chrono>
//using namespace std::chrono;
//int main()
//{
//	list<string> files = {"20", "50", "200", "500", "1K", "2K", "5K", "20K", "50K", "100K", "200K", "500K", "1M", "2M", "3M" };
//	for (string s : files)
//	{
//		cout << s << endl;
//		auto start = high_resolution_clock::now();
//		list<pair<int, string>> results;
//		algorithm("C:/input-papers-" + s + ".txt", results);
//		auto stop = high_resolution_clock::now();
//		auto duration = duration_cast<microseconds>(stop - start);
//		cout << duration.count() << endl;
//	}
//}

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