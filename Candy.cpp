#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
	vector<int> rat;
	unordered_map<int, int> memoization;

	int index = 0;
	int findRecursively(int val)
	{
		index = val;
		if (rat[val - 1] >= rat[val] && rat[val + 1] >= rat[val])
		{
			memoization[val] = 1;
		}
		else if (rat[val - 1] < rat[val] && rat[val + 1] >= rat[val])
		{
			if (memoization.find(val - 1) != memoization.end())
				memoization[val] = memoization.find(val - 1)->second + 1;
			else
				memoization[val] = findRecursively(val - 1) + 1;
		}
		else if (rat[val - 1] >= rat[val] && rat[val + 1] < rat[val])
		{
			if (memoization.find(val + 1) != memoization.end())
				memoization[val] = memoization.find(val + 1)->second + 1;
			else
				memoization[val] = findRecursively(val + 1) + 1;
		}
		else if (rat[val - 1] < rat[val] && rat[val + 1] < rat[val])
		{
			if (rat[val + 1] < rat[val - 1]) {
				if (memoization.find(val - 1) != memoization.end())
					memoization[val] = memoization.find(val - 1)->second + 1;
				else
					memoization[val] = findRecursively(val - 1) + 1;
			}
			else
			{
				if (memoization.find(val + 1) != memoization.end())
					memoization[val] = memoization.find(val + 1)->second + 1;
				else
					memoization[val] = findRecursively(val + 1) + 1;
			}
		}
		return memoization.find(val)->second;
	}

	int candy(vector<int>& ratings) {
		rat = ratings;
		rat.insert(rat.begin(), 20001);
		rat.push_back(20001);
		int result = 0;
		while (index < rat.size() - 2) {
			index += 1;
			findRecursively(index);
		}
		for (auto& res : memoization)
			result += res.second;
		index = 0;
		memoization.clear();
		return result;
	}
};