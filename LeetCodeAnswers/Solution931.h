#pragma once
#ifndef SOLUTION931_H
#define SOLUTION931_H

#include "commonHeader.h"

class Solution931 {
public:
	int minFallingPathSum(vector<vector<int>>& A) {
		vector < vector<int>> B(A);
		for (int i = 1; i < B.size(); i++)
		{
			for (int j = 0; j < B[i].size(); j++)
			{
				int curMin = 9999;
				if (j > 0)
					curMin = B[i - 1][j - 1];
				
				curMin = min(B[i - 1][j], curMin);
				
				if (j + 1 < B[i].size())
					curMin = min(B[i - 1][j + 1], curMin);
				
				B[i][j] += curMin;
			}
		}

		int finalMin = 9999;
		for (int j = 0; j < B[B.size() - 1].size(); j++)
			if (B[B.size() - 1][j] < finalMin)
				finalMin = B[B.size() - 1][j];
		
		return finalMin;
	}
};

#endif