#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// * Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode*> s;
		TreeNode *p = root;
		TreeNode *last = NULL;

		vector<int> v;

		while (p != NULL || !s.empty())
		{
			while (p != NULL)
			{
				s.push(p);
				p = p->left;
			}

			p = s.top();
			if (p->right==NULL || last == p->right)
			{
				v.push_back(p->val);
				last = p;
				p = NULL;
				s.pop();
			}
			else
			{
				p = p->right;
			}
		}

		return v;
    }
};