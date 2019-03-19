#pragma once
#ifndef SOLUTION102_H
#define SOLUTION102_H


#include <vector>
#include <queue>
using namespace std;



struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};


class Solution102 {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {

		vector<vector<int>> traversalResult;

		if (root == NULL) return {};

		queue<pair<TreeNode*, int>> stk;
		stk.push(make_pair(root, 0));

		while (!stk.empty()) {

			TreeNode* temp = stk.front().first;
			int level = stk.front().second;
			stk.pop();

			if (traversalResult.size() <= level)
				traversalResult.push_back({ temp->val });
			else
				traversalResult[level].push_back(temp->val);

			if (temp->left)
				stk.push(make_pair(temp->left, level + 1));

			if (temp->right)
				stk.push(make_pair(temp->right, level + 1));
		}


		return traversalResult;
	}

};

#endif