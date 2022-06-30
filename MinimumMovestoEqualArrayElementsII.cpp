#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int median = 0;
        if (nums.size() % 2 == 1)
            median = nums[nums.size() / 2];
        else
            median = (nums[nums.size() / 2 - 1] + nums[nums.size() / 2]) / 2;
        int result = 0;
        for (int& num : nums)
            result += (int)abs(median - num);
        return result;
    }
};