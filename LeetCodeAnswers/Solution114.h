#pragma once
#ifndef SOLUTION114_H
#define SOLUTION114_H

#define NULL nullptr

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution114 {
public:
	TreeNode* flattenLeft(TreeNode* node)
	{
		TreeNode* thisTail = nullptr;
		while (node)
		{
			if (node->left)
			{
				TreeNode* backup = node->right;
				node->right = node->left;
				TreeNode* tail = flattenLeft(node->left);
				tail->right = backup;
				node->left = nullptr;
				if (!backup)
					thisTail = tail;
				node = backup;
				continue;
			}

			if (!node->right)
				thisTail = node;
			node = node->right;
		}
		return thisTail;
	}

	void flatten(TreeNode* root) {
		flattenLeft(root);
	}
};

#endif