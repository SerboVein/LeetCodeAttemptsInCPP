#pragma once

#define NULL nullptr

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};


class Solution572 {
public:
	bool isSubtree(TreeNode* root1, TreeNode* root2) {
		bool result = false;
		if (root1 != nullptr && root2 != nullptr) {
			if (root1->val == root2->val) {
				result = doesTreeHaveTree(root1, root2);
			}
			if (!result) {
				result = isSubtree(root1->left, root2);
			}
			if (!result) {
				result = isSubtree(root1->right, root2);
			}
		}
		return result;
	}

	bool doesTreeHaveTree(TreeNode* node1, TreeNode* node2) {
		if (node2 == nullptr && node1 == nullptr)
			return true;
		if (node1 == nullptr || node2 == nullptr)
			return false;
		if (node1->val != node2->val)
			return false;
		return doesTreeHaveTree(node1->left, node2->left) && doesTreeHaveTree(node1->right, node2->right);
	}
};