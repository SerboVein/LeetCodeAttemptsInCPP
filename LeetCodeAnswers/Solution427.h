#pragma once
#ifndef SOLUTION427_H
#define SOLUTION427_H

#include <vector>
using namespace std;

class Node {
public:
	bool val;
	bool isLeaf;
	Node* topLeft;
	Node* topRight;
	Node* bottomLeft;
	Node* bottomRight;

	Node() {}

	Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
		val = _val;
		isLeaf = _isLeaf;
		topLeft = _topLeft;
		topRight = _topRight;
		bottomLeft = _bottomLeft;
		bottomRight = _bottomRight;
	}
};

class Solution427 {
public:
	Node* constructNode(const vector<vector<int>>& grid, int stX, int stY, int Len)
	{
		int val = grid[0][0];
		bool isAllTheSame = true;
		Node* thisNode = new Node();
		for (int dx = 0; dx < Len; dx++)
		{
			for (int dy = 0; dy < Len; dy++)
				if (grid[stX + dx][stY + dy] != val)
				{
					isAllTheSame = false;
					break;
				}

			if (!isAllTheSame)
				break;
		}

		if (isAllTheSame)
			return new Node(val == 1, true, nullptr, nullptr, nullptr, nullptr);

		return new Node(false, false, constructNode(grid, stX, stY, Len / 2),
			constructNode(grid, stX + Len / 2, stY, Len / 2),
			constructNode(grid, stX, stY + Len / 2, Len / 2),
			constructNode(grid, stX + Len / 2, stY + Len / 2, Len / 2));
	}

	Node* construct(const vector<vector<int>>& grid) {
		Node* root = constructNode(grid, 0, 0, grid.size());
		return root;
	}
};

#endif