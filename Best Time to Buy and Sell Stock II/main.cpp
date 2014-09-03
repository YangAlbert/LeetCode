#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if (prices.empty())
		{
			return 0;
		}
		else
		{
			int mp = 0;
			for (size_t i=0; i<prices.size()-1; ++i)
			{
				int prof = prices[i+1] - prices[i];
				if (prof > 0)
				{
					mp += prof;
				}
			}

			return mp;
		}
	}
};