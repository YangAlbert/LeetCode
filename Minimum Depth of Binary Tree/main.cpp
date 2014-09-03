#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	int minDp;
	void _recCalcMinDepth(TreeNode *node, int d)
	{
		if (!(node->left || node->right))
		{
			if (d < minDp)
			{
				minDp = d;
			}
		}
		else
		{
			if (node->left) _recCalcMinDepth(node->left, d+1);
			if (node->right) _recCalcMinDepth(node->right, d+1);
		}
	}

public:
    int minDepth(TreeNode *root) {
        if (NULL == root)
		{
			return 0;
		}
		else
		{
			minDp = INT_MAX;
			_recCalcMinDepth(root, 1);
			return minDp;
		}
    }
};