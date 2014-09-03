#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
		// get the length of list.
        int len = 0;
		ListNode *tmp = head;
		while (NULL != tmp)
		{
			++len;
			tmp = tmp->next;
		}

		if (len <= 2) return;
		
		// split list into two parts.
		int hLen = len / 2;
		tmp = head;
		for (int i=0; i<hLen; ++i)
		{
			tmp = tmp->next;
		}

		ListNode *rHead = tmp->next;
		tmp->next = NULL;

		// reverse last part list.
		rHead	= reverseList(rHead);
		tmp		= head;

		// merge two lists.
		while (tmp != NULL && rHead != NULL)
		{
			ListNode *lhs = tmp;
			ListNode *rhs = rHead;

			tmp = tmp->next;
			rHead = rHead->next;

			lhs->next = rhs;
			rhs->next = tmp;
		}
    }

	ListNode* reverseList(ListNode *head) {
		ListNode *tail = head;
		while (NULL != tail->next) tail = tail->next;

		while (head != tail)
		{
			ListNode *tmp = head;
			head = head->next;

			tmp->next = tail->next;
			tail->next = tmp;
		}

		return tail;
	}
};