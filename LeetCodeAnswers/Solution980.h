#pragma once
#ifndef SOLUTION980_H
#define SOLUTION980_H

#include <vector>
using namespace std;

class Solution980 {
public:
	bool checkValidPath(vector<vector<int>>& grid)
	{
		for (int i = 0; i < grid.size(); i++)
			for (int j = 0; j < grid[i].size(); j++)
				if (grid[i][j] == 0)
					return false;

		return true;
	}

	void findPaths(vector<vector<int>>& grid, int x, int y)
	{
		if (x < 0 || y < 0 || x >= grid.size() || y >= grid[x].size())
			return;

		if (grid[x][y] == 2)
		{
			if(checkValidPath(grid))
				nUniquePaths++;
			return;
		}

		if (grid[x][y] == -1)
			return;

		grid[x][y] = -1;
		findPaths(grid, x + 1, y);
		findPaths(grid, x, y + 1);
		findPaths(grid, x, y - 1);
		findPaths(grid, x - 1, y);
		grid[x][y] = 0;
	}

	int uniquePathsIII(vector<vector<int>>& grid) {
		for (int i = 0; i < grid.size(); i++)
			for (int j = 0; j < grid[i].size(); j++)
				if (grid[i][j] == 1)
				{
					findPaths(grid, i, j);
					return nUniquePaths;
				}

		return nUniquePaths;
	}
private:
	int nUniquePaths = 0;
};



#endif