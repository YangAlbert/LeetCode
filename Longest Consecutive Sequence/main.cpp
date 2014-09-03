#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

//class Solution {
//public:
//	int longestConsecutive(vector<int> &num) {
//		vector<int> flags;
//
//		int maxLen = 0;
//
//		for (size_t i=0; i<num.size(); ++i)
//		{
//			flags.assign(num.size(), 0);
//
//			for (size_t j=0; j<num.size(); ++j)
//			{
//				int diff = num[i] - num[j];
//				if (diff >= 0 && diff < (int)flags.size())
//				{
//					flags[diff] = 1;
//				}
//			}
//
//			size_t len = 0;
//			for (; len<flags.size() && flags[len]==1; ++len) ;
//			if ((int)len > maxLen) maxLen = (int)len;
//		}
//
//		return maxLen;
//	}
//};

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
			else
			{
				len = 1;
			}
		}

		return maxLen;
	}
};