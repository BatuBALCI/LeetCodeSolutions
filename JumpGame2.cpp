#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
	unordered_map<int, int> memoizationMap;

	int JumpCount(vector<int>& nums, int index) {
		auto value = nums[index];
		int ret;

		if ((index + value) >= nums.size() - 1)
			return 1;
		else if (value == 0)
			return 0;
		else
		{
			int min = nums.size();
			for (int i = 1; i <= value; i++)
			{
				auto find = memoizationMap.find(index + i);
				if (find == memoizationMap.end()) {
					ret = JumpCount(nums, index + i);
					memoizationMap[index + i] = ret;
					if (ret != 0)
						min = min < ret ? min : ret;
					else
						if (i == value && min == nums.size())
							min = 0;
				}
				else {
					ret = find->second;
					if (ret != 0)
						min = min < ret ? min : ret;
					else
						if (i == value && min == nums.size())
							min = 0;
				}
			}
			if (min == 0)
				return 0;
			else
				return 1 + min;
			return 0;
		}
	}

	int jump(vector<int>& nums)
	{
		if (nums.size() == 1)
			return 0;
		int res = JumpCount(nums, 0);
		memoizationMap.clear();
		return res;
	}
};
