#ifndef SOLUTION508_H
#define SOLUTION508_H


#include <map>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
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


struct CmpByValue {
	bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
		return lhs.second < rhs.second;
	}
};

class Solution {
public:
	int getSubTreeSum(TreeNode* thisNode, map<int, int> &Hist)
	{
		int Sum = thisNode->val;
		if (thisNode->left)
			Sum += getSubTreeSum(thisNode->left, Hist);
		if (thisNode->right)
			Sum += getSubTreeSum(thisNode->right, Hist);

		Hist[Sum]++;
		return Sum;
	}

	vector<int> findFrequentTreeSum(TreeNode* root) {
		map<int, int> Hist;
		getSubTreeSum(root, Hist);
		sort(Hist.begin(), Hist.end(), CmpByValue());
		vector<int> result = {};
		return result;
	}
};


#endif

#pragma once
