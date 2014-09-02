#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        s = process(s);

		int l = 0;
		int r = (int)s.length() - 1;
		while (l < r) {
			if (s[l++] != s[r--]) return false;
		}

		return true;
    }

	string process(const string& s) {
		string ret;
		for (size_t i=0; i<s.length(); ++i) {
			if ((s[i] >= 'a' && s[i] <= 'z') ||
				(s[i] >= '0' && s[i] <= '9')) {
				ret.push_back(s[i]);
			}
			else if (s[i] >= 'A' && s[i] <= 'Z') {
				ret.push_back(s[i] - 'A' + 'a');
			}
		}

		return ret;
	}
};