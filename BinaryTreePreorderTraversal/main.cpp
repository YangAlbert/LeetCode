#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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
public:
    vector<int> preorderTraversal(TreeNode *root) {
		vector<int> ptVec;

		stack<TreeNode*> nodeS;
		if (NULL != root) nodeS.push(root);

		while (!nodeS.empty())
		{
			TreeNode* pNd = nodeS.top();
			ptVec.push_back(pNd->val);

			nodeS.pop();

			if (NULL != pNd->right) nodeS.push(pNd->right);
			if (NULL != pNd->left) nodeS.push(pNd->left);
		}

		return ptVec;
    }
};