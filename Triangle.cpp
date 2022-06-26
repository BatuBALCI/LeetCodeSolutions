#include <vector>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 1; i >= 0; i--)
        {
            if (i + 1 >= triangle.size())
                continue;
            for (int j = 0; j < triangle.at(i).size(); j++)
                triangle.at(i).at(j) = (triangle.at(i + 1).at(j) < triangle.at(i + 1).at(j + 1) ? triangle.at(i + 1).at(j) : triangle.at(i + 1).at(j + 1)) + triangle.at(i).at(j);
        }
        return triangle.at(0).at(0);
    }
};