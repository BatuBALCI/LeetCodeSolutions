#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b)
    {
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), comp);
        int result = 0;
        for (auto& vec : boxTypes)
        {
            if (vec[0] < truckSize)
            {
                result += vec[0] * vec[1];
                truckSize -= vec[0];
            }
            else
            {
                result += truckSize * vec[1];
                break;
            }
        }
        return result;
    }
};