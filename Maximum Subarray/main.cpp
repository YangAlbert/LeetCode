#include <vector>
using namespace std;

class Solution {
public:
	int maxSubArray(int A[], int n) {
		if (n <= 0)
		{
			return 0;
		}
		else
		{
			int local, global;
			local = global = A[0];

			for (int i=1; i<n; ++i)
			{
				local = max(A[i], local + A[i]);
				global = max(global, local);
			}

			return global;
		}
	}
};