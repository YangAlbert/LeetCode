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
private:
	int sum;

public:
    int sumNumbers(TreeNode *root) {
		if (NULL == root) return 0;

		sum = 0;
		DFS(root, 0);

		return sum;
    }

	void DFS(TreeNode *node, int val) {
		int tmp = val * 10 + node->val;
		if (NULL == node->left && NULL == node->right)
		{
			sum += tmp;
		}
		else 
		{
			if (NULL != node->left) DFS(node->left, tmp);
			if (NULL != node->right) DFS(node->right, tmp);
		}
	}
};