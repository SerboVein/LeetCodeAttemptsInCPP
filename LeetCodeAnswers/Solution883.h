#pragma once
#ifndef SOLUTION883_H
#define SOLUTION883_H

#include <vector>
using namespace std;


class Solution883 {
public:
	int projectionArea(vector<vector<int>>& grid) {
		int totalArea = 0;
		vector<int> maxHeightofJ(grid[0].size());

		for (int i = 0; i < grid.size(); i++)
		{
			int maxHeightofi = 0;
			for (int j = 0; j < grid[0].size(); j++)
			{
				if (grid[i][j])
				{
					if (grid[i][j] > maxHeightofi)
						maxHeightofi = grid[i][j];
					if (grid[i][j] > maxHeightofJ[j])
						maxHeightofJ[j] = grid[i][j];
					totalArea += 1;
				}
			}
			totalArea += maxHeightofi;
		}

		for (auto maxHeight : maxHeightofJ)
			totalArea += maxHeight;

		return totalArea;
	}
};

#endif