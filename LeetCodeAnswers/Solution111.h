#pragma once
#ifndef SOLUTION111_H
#define SOLUTION111_H

#define NULL nullptr

#include <minmax.h>
#include <cmath>

struct TreeNode {
		int val;
		TreeNode *left;
 		TreeNode *right;
 		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution111 {
public:
	int findDepthMin(TreeNode* node, int depth)
	{
		if (!node)
			return depth - 1;

		if ((!node->left) && (!node->right))
			return depth;

		int mindepth = 99999;
		if (node->left)
			mindepth = findDepthMin(node->left, depth + 1);
		if (node->right)
			mindepth = min(depth, findDepthMin(node->right, depth + 1));

		return mindepth;
	}

	int minDepth(TreeNode* root) {
		return findDepthMin(root, 1);
	}
};


/*  this is a better answer than before
class Solution {
public:
	int findDepthMin(TreeNode* node,int depth)
	{
		if(!node)
			return 99999;

		if((!node->left) && (!node->right))
			return depth;

		return min(findDepthMin(node->left,depth+1),findDepthMin(node->right,depth+1));
	}

	int minDepth(TreeNode* root) {
		if(!root)
			return 0;

		return findDepthMin(root,1);
	}
};

*/

#endif