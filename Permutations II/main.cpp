#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > permuteUnique(vector<int> &num) {
		sort(num.begin(), num.end());

		vector<vector<int> > permArr;
		permArr.push_back(num);

		for (int i=0; i<num.size(); ++i)
		{
			if (i > 0 && num[i] == num[i-1]) continue;
			for (int j=0; j<num.size(); ++j)
			{
				if (j == i) continue;

				vector<int> perm;
				if (j > 0) {
					perm.insert(perm.end(), num.begin(), num.begin()+j);
				}

			}
		}
	}
};