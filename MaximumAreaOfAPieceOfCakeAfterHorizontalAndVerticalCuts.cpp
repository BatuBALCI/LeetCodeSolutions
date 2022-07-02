#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int maxh = 0, maxv = 0;
        int i;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        for (i = 0; i < horizontalCuts.size() + 1; i++)
        {
            if (i == 0)
                maxh = maxh < (horizontalCuts[i] - 0) ? (horizontalCuts[i] - 0) : maxh;
            else if (i == horizontalCuts.size())
                maxh = maxh < (h - horizontalCuts[i - 1]) ? (h - horizontalCuts[i - 1]) : maxh;
            else
                maxh = maxh < (horizontalCuts[i] - horizontalCuts[i - 1]) ? (horizontalCuts[i] - horizontalCuts[i - 1]) : maxh;
        }
        for (i = 0; i < verticalCuts.size() + 1; i++)
        {
            if (i == 0)
                maxv = maxv < (verticalCuts[i] - 0) ? (verticalCuts[i] - 0) : maxv;
            else if (i == verticalCuts.size())
                maxv = maxv < (w - verticalCuts[i - 1]) ? (w - verticalCuts[i - 1]) : maxv;
            else
                maxv = maxv < (verticalCuts[i] - verticalCuts[i - 1]) ? (verticalCuts[i] - verticalCuts[i - 1]) : maxv;
        }
        return (1LL * maxh * maxv) % 1000000007;
    }
};