#include <string>
#include <unorder_map>
#include <map>
using namespace std;

class Solution {
public:
	map<int, int> findFreqs(string s)
	{
		unordered_map<char, int> charMap;
		map<int, int> intMap;
		for (char& chr : s)
		{
			auto foundFreq = charMap.find(chr);
			if (foundFreq != charMap.end()) {
				int newFreq = foundFreq->second + 1;
				charMap.erase(chr);
				charMap[chr] = newFreq;
			}
			else
				charMap[chr] = 1;
		}

		for (auto& chr : charMap)
		{
			auto foundFreq = intMap.find(chr.second);
			if (foundFreq != intMap.end()) {
				int newFreq = foundFreq->second + 1;
				intMap.erase(chr.second);
				intMap[chr.second] = newFreq;
			}
			else
				intMap[chr.second] = 1;
		}
		return intMap;
	}

	int sum(int distance, int& result, int hold)
	{
		if (hold >= distance) {
			int a = (hold - distance);
			result += hold * (hold + 1) / 2 - a * (a + 1) / 2;
			return a + 1;
		}
		else {
			result += hold * (hold + 1) / 2;
			return 0;
		}
	}

	int minDeletions(string s) {

		auto mapFreq = findFreqs(s);
		auto a = mapFreq.end();
		int holdVal = 0;
		auto b = a;
		--b;
		int holdKey = b->first;
		int result = 0;
		while (true)
		{
			--a;
			result += holdVal;
			if (holdKey == a->first) {
				if (a->second > 1)
					holdVal += a->second - 1;
			}
			else
			{
				if (holdVal > 0) {
					int temp = sum((holdKey)-a->first, result, holdVal - 1);
					if (a->second > 1)
						holdVal = a->second - 1 + temp;
					else
						holdVal = temp;
				}
				else {
					if (a->second > 1)
						holdVal = a->second - 1;
					else
						holdVal = 0;
				}
			}

			holdKey = a->first - 1;

			if (a == mapFreq.begin()) {
				if (holdVal > 0)
					sum(holdKey + 1, result, holdVal);
				break;
			}
		}
		return result;
	}

};