#include <string>
using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		if (s.length() == 0 || s[0] == '0') 
		{
			return 0;
		}
		else
		{
			int d1 = 1, d2 = 1, nd=1;
			for (size_t i=1; i<s.length(); ++i)
			{
				if (s[i] == '0')
				{
					if (s[i-1]=='1' || s[i-1]=='2')
					{
						nd = d1;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					if (s[i-1] == '1' || (s[i-1]=='2' && s[i]>='1' && s[i]<='6'))
					{
						nd = d1 + d2;
					}
					else
					{
						nd = d2;
					}
				}

				d1 = d2, d2 = nd;
			}

			return nd;
		}
	}
};