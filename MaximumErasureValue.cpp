#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
	int maximumUniqueSubarray(vector<int>& nums) {
		int maxSum = 0;
		int sum = 0;
		int resSum = 0;
		int lastExtracted = 0;
		int lastIndex = 0;
		int counter = 0;
		unordered_map<int, pair<int, int>> numHash;
		for (auto i = nums.begin(); i < nums.end(); i++)
		{
			sum += *i;
			if (numHash.find(*i) != numHash.end())
			{
				auto pairFound = numHash.find(*i)->second;
				for (int& a = lastIndex; a < pairFound.first + 1; a++)
					numHash.erase(nums.at(a));
				lastIndex = pairFound.first + 1;
				resSum = sum - pairFound.second;
				lastExtracted = pairFound.second;
				numHash[*i] = pair<int, int>(counter, sum);
			}
			else
			{
				numHash[*i] = pair<int, int>(counter, sum);
				resSum = sum - lastExtracted;
			}
			counter++;
			maxSum = resSum < maxSum ? maxSum : resSum;
		}
		return maxSum;
	}
};