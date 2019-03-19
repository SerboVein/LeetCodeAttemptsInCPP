#pragma once
#ifndef SOLUTION559_H
#define SOLUTION559_H

#include <vector>
#include <minmax.h>
using namespace std;


class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};


class Solution559 {
public:
	int getDepth(Node* node, int depth) {
		if (!node)
			return depth - 1;

		int thisDepth = 0;
		for (auto child : node->children)
		{
			thisDepth = max(thisDepth, getDepth(child, depth + 1));
		}

		return thisDepth;
	}

	int maxDepth(Node* root) {
		return getDepth(root, 1);
	}
};


#endif