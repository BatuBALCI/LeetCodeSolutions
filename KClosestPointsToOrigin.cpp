#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
		priority_queue<pair<int, vector<int>>> pr_queue;
		vector<vector<int>> result;
		int count = 0;
		for (auto& point : points)
		{
			int distance = pow(point[0], 2) + pow(point[1], 2);
			if (count < k) {
				pr_queue.push(pair<int, vector<int>>(distance, point));
			}
			else
			{
				if (pr_queue.top().first > distance)
				{
					pr_queue.pop();
					pr_queue.push(pair<int, vector<int>>(distance, point));;
				}
			}
			count++;
		}
		while (pr_queue.size())
		{
			result.push_back(pr_queue.top().second);
			pr_queue.pop();
		}
		return result;

	}
};
