#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode *head) {
		ListNode *n1 = head;
		ListNode *n2 = head;

		if (n2 == NULL || n2->next == NULL) return false;
		n2 = n2->next->next;

		while (NULL != n2)
		{
			if (n1 == n2) return true;

			n1 = n1->next;

			if (n2->next) n2 = n2->next->next;
			else return false;
		}

		return false;
	}
};