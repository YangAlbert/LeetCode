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
	int maxSum;

	int _recMaxPathSum(TreeNode *node)
	{
		if (NULL == node)
		{
			return 0;
		}
		else if (!(node->left || node->right))
		{
			if (node->val > maxSum)
			{
				maxSum = node->val;
			}

			return (node->val > 0 ? node->val : 0);
		}
		else
		{
			int leftSum = _recMaxPathSum(node->left);
			int rightSum = _recMaxPathSum(node->right);

			int sum = leftSum + rightSum + node->val;
			if (sum > maxSum) maxSum = sum;

			int ret = max(leftSum, rightSum) + node->val;
			return (ret > 0 ? ret : 0);
		}
	}

public:
    int maxPathSum(TreeNode *root) {
		maxSum = INT_MIN;
		_recMaxPathSum(root);

		return maxSum;
    }
};