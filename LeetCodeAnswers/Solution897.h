#pragma once
#ifndef SOLUTION897_H
#define SOLUTION897_H




struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}   //why is NULL sometimes defined , sometimes not??? 
 };

class Solution897 {
public:


	// in this code , i encountered the problem of order when changing recursive into function stack. 
	TreeNode* increasingBST(TreeNode* root) {

		if (!root)
			return nullptr;

		TreeNode *increasingTreeBk = new TreeNode(0);
		this->increasingTree = increasingTreeBk;

		stack<TreeNode*> stk;
		stk.push(root);

		while (!stk.empty())
		{
			TreeNode* node = stk.top();
			stk.pop();

			if (!node)
				continue;

			stk.push(node->left);
			increasingTree->right = new TreeNode(node->val);
			increasingTree = increasingTree->right;
			stk.push(node->right);
		}

		return increasingTreeBk;
	}


private:

	TreeNode* increasingTree;

};

#endif