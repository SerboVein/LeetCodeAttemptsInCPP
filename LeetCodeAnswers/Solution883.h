#pragma once
#ifndef SOLUTION883_H
#define SOLUTION883_H

#include <vector>
using namespace std;

/*
	this is very genius solution compared with mine.......... fascinating. 

	for (int i = 0; i < N;  ++i) {
			int bestRow = 0;  // largest of grid[i][j]
			int bestCol = 0;  // largest of grid[j][i]
			for (int j = 0; j < N; ++j) {
				if (grid[i][j] > 0) ans++;  // top shadow
				bestRow = max(bestRow, grid[i][j]);
				bestCol = max(bestCol, grid[j][i]);
			}
			ans += bestRow + bestCol;
		}


*/


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