#include <iostream>
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
	int listLength(ListNode *head, ListNode *& tail)
	{
		if (NULL == head)
		{
			tail = NULL;
			return 0;
		}
		else
		{
			int len = 1;
			while (head->next != NULL)
			{
				++len;
				head = head->next;
			}

			tail = head;
			return len;
		}
	}

public:
    ListNode *rotateRight(ListNode *head, int k) {
		ListNode *tail;
		int len = listLength(head, tail);
		if (len <= 1)
		{
			return head;
		}

		k = k % len;
		if (k != 0)
		{
			ListNode *pNode = head;
			for (int i=0; i<len-1-k; ++i)
			{
				pNode = pNode->next;
			}

			ListNode *pNewHead = pNode->next;
			tail->next = head;
			pNode->next = NULL;

			return pNewHead;
		}
		else
		{
			return head;
		}
    }
};