#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > permuteUnique(vector<int> &num) {
		sort(num.begin(), num.end());

		vector<vector<int> > permVec;
		permVec.push_back(num);

		for (int i=0; i<(int)num.size()-1; ++i)
		{
			if (i>0 && num[i] == num[i-1]) continue;

			for (int j=i+1; j<(int)num.size(); ++j)
			{
				if (num[i] == num[j]) continue;

				vector<int> perm;
				if (i > 0) {
					perm.insert(perm.end(), num.begin(), num.begin()+i);
				}
				perm.insert(perm.end(), num.begin()+i+1, num.begin()+j+1);
				perm.push_back(num[i]);
				if (j < num.size()-1) {
					perm.insert(perm.end(), num.begin()+j+1, num.end());
				}

				permVec.push_back(perm);
			}
		}

		return permVec;
	}
};

void main() {
	vector<int> num;
	int nCnt = 1;

	cout << "input num count: ";
	cin >> nCnt;

	num.resize(nCnt);
	cout << "input numbers: ";
	for (int i=0; i<nCnt; ++i)
	{
		cin >> num[i];
	}

	vector<vector<int> > permVec = Solution().permuteUnique(num);

	for (int i=0; i<permVec.size(); ++i) {
		for (int j=0; j<permVec[i].size(); ++j) {
			cout << permVec[i][j] << ' ';
		}
		cout << endl;
	}
}