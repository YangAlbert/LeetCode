#include <iostream>
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
	int tarSum;
	bool _recCheckSum(TreeNode *node, int sum)
	{
		sum += node->val;
		if (!(node->left || node->right))
		{
			return (sum==tarSum);
		}
		else
		{
			bool bRet =false;
			if (node->left)
			{
				bRet = _recCheckSum(node->left, sum);
			}
			if (!bRet && node->right)
			{
				bRet = _recCheckSum(node->right, sum);
			}

			return bRet;
		}
	}

public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (NULL == root)
		{
			return false;
		}
		else
		{
			tarSum = sum;
			return _recCheckSum(root, 0);
		}
    }
};