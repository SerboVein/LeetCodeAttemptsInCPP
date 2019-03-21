#pragma once
#ifndef SOLUTION766_H
#define SOLUTION766_H

#include <vector>
using namespace std;

class Solution766 {
public:
	bool isToeplitzMatrix(const vector<vector<int>>& matrix) {
		for (int i = matrix.size() - 2; i >= -((int)matrix[0].size() - 2); i--)
		{
			int firstElem;
			int j = 0;
			if (i < 0)
			{
				j = -i;
				firstElem = matrix[0][j];
				j++;
			}
			else
				firstElem = matrix[i][0];

			while (true)
			{
				if (i + j >= matrix.size() || j >= matrix[0].size())
					break;
				if (matrix[i + j][j] != firstElem)
					return false;
			}

		}
		return true;
	}
};


#endif