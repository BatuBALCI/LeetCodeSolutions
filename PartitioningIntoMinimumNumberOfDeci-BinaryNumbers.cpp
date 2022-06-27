#include <string>
using namespace std;

int minPartitions(string n) {
	int max = 0;
	for (char& chr : n)
	{
		max = max < ((int)chr - 48) ? ((int)chr - 48) : max;
		if (max == 9)
			return max;
	}
	return max;
}
