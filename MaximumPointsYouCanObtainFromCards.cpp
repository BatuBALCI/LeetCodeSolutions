#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
	int maxScore(vector<int>& cardPoints, int k) {
		int firstSum = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
		int maxSum = firstSum;
		for (int i = 0; i < k; i++)
		{
			firstSum = firstSum - cardPoints[k - 1 - i] + cardPoints[cardPoints.size() - (1 + i)];
			maxSum = maxSum < firstSum ? firstSum : maxSum;
		}
		return maxSum;
	}
};