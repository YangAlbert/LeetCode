#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int numTrees(int n) {
		if (n <= 0)
		{
			return 0;
		}
		vector<int> res;
		res.resize(n+1);
		res[0] = 1;
		res[1] = 1;
		for (int i=2; i<=n; ++i)
		{
			res[i] = 0;
			for (int j=0; j<i; ++j)
			{
				res[i] += res[j] * res[i-1-j];
			}
		}
		
		return res[n];
	}
};