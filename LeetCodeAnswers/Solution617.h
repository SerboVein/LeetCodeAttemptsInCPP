#pragma once
#ifndef SOLUTION617_H
#define SOLUTION617_H

#define NULL nullptr

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution617 {
public:
	void mergeNode(TreeNode* t1, TreeNode* mergedNode)
	{
		mergedNode->val = t1->val;
		if (t1->left)
		{
			mergedNode->left = new TreeNode(0);
			mergeNode(t1->left, mergedNode->left);
		}
		else
			mergedNode->left = nullptr;

		if (t1->right)
		{
			mergedNode->right = new TreeNode(0);
			mergeNode(t1->right, mergedNode->right);
		}
		else
			mergedNode->right = nullptr;
	}

	void mergeNode(TreeNode* t1, TreeNode* t2, TreeNode* mergedNode)
	{
		mergedNode->val = t1->val + t2->val;
		if (t1->left && t2->left)
		{
			mergedNode->left = new TreeNode(0);
			mergeNode(t1->left, t2->left, mergedNode->left);
		}
		else if (t1->left)
		{
			mergedNode->left = new TreeNode(0);
			mergeNode(t1->left, mergedNode->left);
		}
		else if (t2->left)
		{
			mergedNode->left = new TreeNode(0);
			mergeNode(t2->left, mergedNode->left);
		}
		else
			mergedNode->left = nullptr;

		if (t1->right && t2->right)
		{
			mergedNode->right = new TreeNode(0);
			mergeNode(t1->right, t2->right, mergedNode->right);
		}
		else if (t1->right)
		{
			mergedNode->right = new TreeNode(0);
			mergeNode(t1->right, mergedNode->right);
		}
		else if (t2->right)
		{
			mergedNode->right = new TreeNode(0);
			mergeNode(t2->right, mergedNode->right);
		}
		else
			mergedNode->right = nullptr;

	}

	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		TreeNode* mergedTree = new TreeNode(0);
		mergeNode(t1, t2, mergedTree);
		return mergedTree;
	}
};

/*  this is the re-constructed codes that is much clearer and shorter than before

class Solution {
public:

	TreeNode* mergeNode(TreeNode* t1, TreeNode* t2)
	{
		if(!t1 && !t2)
			return nullptr;

		int val = 0;
		if(t1)
			val += t1->val;
		if(t2)
			val += t2->val;

		TreeNode* thisNode = new TreeNode(val);
		thisNode->left = mergeNode(t1 ? t1->left : nullptr, t2 ? t2->left : nullptr);
		thisNode->right = mergeNode(t1 ? t1->right : nullptr, t2 ? t2->right : nullptr);

		return thisNode;
	}


	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		return mergeNode(t1, t2);
	}
};

*/

/*
      ************** this version hasn't allocated new memory for single branch situation , thus saves a lot of branch copying time.
					  but this is not a good measure!!!, so the code above is memory safe, allocates new memory and is good code. 

class Solution {
public:

	TreeNode* mergeNode(TreeNode* t1, TreeNode* t2)
	{
		if(!t1 && !t2)
			return nullptr;

		if(!t1 || !t2)
			return t1 ? t1 : t2;


		// int val = t1->val + t2->val;

		TreeNode* thisNode = new TreeNode(t1->val + t2->val);
		thisNode->left = mergeNode(t1->left,t2->left);
		thisNode->right = mergeNode(t1->right,t2->right);
		// thisNode->left = mergeNode(t1 ? t1->left : nullptr, t2 ? t2->left : nullptr);
		// thisNode->right = mergeNode(t1 ? t1->right : nullptr, t2 ? t2->right : nullptr);

		return thisNode;
	}


	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		return mergeNode(t1, t2);
	}
};
*/



#endif