#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		sort(people.begin(), people.end());
		vector<vector<int>> result(people.size());

		for (auto& vec : people) {
			int count = 0;
			int place = 0;
			int check = 0;
			while (true)
			{
				if (result[count].size() == 0 || result[count][0] == vec[0])
				{
					if (check == vec[1]) {
						result[place + check] = vec;
						break;
					}
					check++;
				}
				else
					place++;
				count++;
			}
		}
		return result;
	}
};