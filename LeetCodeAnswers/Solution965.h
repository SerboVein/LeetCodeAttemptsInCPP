#pragma once
#ifndef SOLUTION965_H
#define SOLUTION965_H

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#define NULL nullptr

 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};


class Solution965 {
public:
	bool checkUnivalNode(TreeNode* thisNode, int unival)
	{
		if (!thisNode)
			return true;

		return thisNode->val == unival &&
			checkUnivalNode(thisNode->left, unival) &&
			checkUnivalNode(thisNode->right, unival);
	}

	bool isUnivalTree(TreeNode* root) {
		return checkUnivalNode(root->left, root->val) &&
			checkUnivalNode(root->right, root->val);
	}
};

#endif