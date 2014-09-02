#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		sort(num.begin(), num.end());

		int maxLen = 1;
		int len = 1;
		for (size_t i=1; i<num.size(); ++i)
		{
			if (num[i]-num[i-1] == 1)
			{
				maxLen = ++len > maxLen ?  len : maxLen;
			}
			else if (num[i] - num[i-1] != 0)
			{
				len = 1;
			}
		}

		return maxLen;
	}
};