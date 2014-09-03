#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if (prices.size() == 0)
		{
			return 0;
		}
		else
		{
			int local, global;
			local = global = 0;

			for (size_t i=0; i<prices.size()-1; ++i)
			{
				local = max(local + prices[i+1]-prices[i], 0);
				global = max(global, local);
			}

			return global;
		}
	}
};