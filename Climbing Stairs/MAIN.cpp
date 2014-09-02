class Solution {
public:
	int climbStairs(int n) {
		if (n < 3) return n;

		int n1=1, n2=2, s;
		for (int i=2; i<n; ++i)
		{
			s = n1 + n2;
			n1 = n2;
			n2 = s;
		}

		return s;
	}
};