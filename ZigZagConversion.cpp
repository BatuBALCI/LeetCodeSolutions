#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<pair<int, char>> results;
        int row = 1;
        bool incrs = true;
        for (char& chr : s)
        {
            pair<int, char> pr({ row, chr });
            results.push_back(pr);
            if (row == numRows)
                incrs = false;
            if (row == 1)
                incrs = true;

            if (incrs)
                row++;
            else
                row--;
        }
        row = 1;
        auto size = s.size();
        s.clear();
        auto iter = results.begin();
        while (true)
        {
            if (iter->first == row)
                s.push_back(iter->second);

            iter++;
            if (iter == results.end()) {
                iter = results.begin();
                row++;
            }
            if (s.size() == size)
                break;
        }
        return s;
    }
};