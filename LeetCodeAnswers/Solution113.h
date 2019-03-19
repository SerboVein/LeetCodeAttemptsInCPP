#pragma once
#ifndef SOLUTION113_H
#define SOLUTION113_H
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


//how to understand further about the difference of stack and vector is my next step. 

// to understand more and more about the difference of stack and vector 

class Solution {
public:

	void findSum(TreeNode* node, int halfSum)
	{
		path.push(node->val);

		int thisSum = halfSum + node->val;

		if (thisSum == sum && !node->left && !node->right)
		{
			vector<int> temp;
			//vector<int> temp(path.top()-path.size()+1,path.top());   
			Allpaths.push_back(temp);
			path.pop();
			return;
		}

		if (node->left)
			findSum(node->left, thisSum);

		if (node->right)
			findSum(node->right, thisSum);
		path.pop();

	}

	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		this->sum = sum;
		if (root)
			findSum(root, 0);

		return Allpaths;
	}

private:
	int sum;
	stack<int, vector<int>> path;
	vector<vector<int>> Allpaths;
};

#endif