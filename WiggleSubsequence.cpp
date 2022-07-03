#include <vector>
using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        // true means increase, false means decrease.
        bool state;
        bool statePrev;
        int count = 1;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (!(nums[i] == nums[i + 1]))
            {
                state = nums[i] <= nums[i + 1];
                if (state != statePrev || count == 1)
                    count++;
            }

            statePrev = state;
        }
        return count;
    }
};