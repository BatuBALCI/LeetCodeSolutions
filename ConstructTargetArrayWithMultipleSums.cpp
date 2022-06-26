#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	long sumLeet(vector<int>& target)
	{
		long sum = 0;
		for (auto a : target)
			sum += a;
		return sum;
	}

	bool isPossible(vector<int>& target) {


		long size = target.size();
		if (sumLeet(target) == size)
			return true;
		long totalSum = sumLeet(target);
		while (true)
		{
			auto max2 = max_element(target.begin(), target.end());

			long sum2 = totalSum - *max2;

			if (sum2 < 1)
				return false;
			else if (totalSum == size)
				return true;
			else {
				if (sum2 * 2 < *max2) {
					target[max2 - target.begin()] = *max2 % sum2 + sum2;
					totalSum = *max2 + sum2;
				}
				else {
					target[max2 - target.begin()] = *max2 - sum2;
					totalSum = totalSum - sum2;
				}
			}
			auto min2 = min_element(target.begin(), target.end());
			if (*min2 < 1)
				return false;
		}
	}
};
