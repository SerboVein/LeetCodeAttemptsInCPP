#ifndef SOLUTION508_H
#define SOLUTION508_H


#include <map>
#include <vector>
#include <unordered_map>
#include <algorithm>
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

typedef pair<int, int> PAIR;

struct CmpByValue {
	bool operator()(const PAIR& k1, const PAIR& k2)const {
		return k1.second > k2.second;
	}
};

struct myclass {
	bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
		return lhs.second < rhs.second;
	}
}myobject;

class Solution508 {
public:
	int getSubTreeSum(TreeNode* thisNode, unordered_map<int, int> &Hist)   //unordered_map is much better, got 99.01 better time efficiency 
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
		vector<int> result = {};
		if (!root)
			return result;

		unordered_map<int, int> Hist;
		getSubTreeSum(root, Hist);
		vector<PAIR> name_score_vec(Hist.begin(), Hist.end());
		sort(name_score_vec.begin(), name_score_vec.end(), CmpByValue());
		int val = name_score_vec[0].second;
		for (int i = 0; i < name_score_vec.size(); i++)
		{
			if (name_score_vec[i].second != val)
				break;

			result.push_back(name_score_vec[i].first);
		}

		return result;
	}
};

#endif
#pragma once
