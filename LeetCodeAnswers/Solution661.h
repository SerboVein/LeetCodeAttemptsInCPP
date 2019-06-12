#pragma once
#ifndef SOLUTION661_H
#include "commonHeader.h"

class Solution661 {
public:
	inline static int smoothWithCertainty(vector<vector<int>>& M, int i, int j)
	{
		return (M[i][j] + M[i - 1][j] + M[i - 1][j - 1] + M[i - 1][j + 1] + M[i + 1][j]
			+ M[i + 1][j - 1] + M[i + 1][j + 1] + M[i][j - 1] + M[i][j + 1]) / 9;
	}

	vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
		vector<vector<int>> ans(M);
		ans[0][0] = (M[1][0] + M[0][0] + M[0][1] + M[1][1]) / 4;
		ans[M.size() - 1][0] = (M[M.size() - 1][1] + M[M.size() - 1][0] + M[M.size() - 2][0] + M[M.size() - 2][1]) / 4;
		ans[M.size() - 1][M[0].size() - 1] = (M[M.size() - 1][M[0].size() - 1] + M[M.size() - 1][M[0].size() - 2]
			+ M[M.size() - 2][M[0].size() - 1] + M[M.size() - 2][M[0].size() - 2]) / 4;
		ans[0][M[0].size() - 1] = (M[0][M[0].size() - 1] + M[0][M[0].size() - 2]
			+ M[1][M[0].size() - 1] + M[1][M[0].size() - 2]) / 4;

		for (int i = 1; i + 1 < M.size(); i++)
		{
			ans[i][0] = (M[i - 1][0] + M[i + 1][0] + M[i][1] + M[i - 1][1] + M[i + 1][1] + M[i][0]) / 6;
			ans[i][M[0].size() - 1] = (M[i - 1][M[0].size() - 1] + M[i + 1][M[0].size() - 1] + M[i][M[0].size() - 1] + M[i][M[0].size() - 2] + M[i - 1][M[0].size() - 2] + M[i + 1][M[0].size() - 2]) / 6;
		}

		for (int j = 1; j + 1 < M[0].size(); j++)
		{
			ans[0][j] = (M[0][j - 1] + M[0][j + 1] + M[0][j] + M[1][j] + M[1][j - 1] + M[1][j + 1]) / 6;
			ans[M.size() - 1][j] = (M[M.size() - 1][j - 1] + M[M.size() - 1][j + 1] + M[M.size() - 1][j]
				+ M[M.size() - 2][j] + M[M.size() - 2][j - 1] + M[M.size() - 2][j + 1]) / 6;
		}


		for (int i = 1; i + 1 < M.size(); i++)
			for (int j = 1; j + 1 < M[0].size(); j++)
				ans[i][j] = smoothWithCertainty(M, i, j);

		return ans;
	}
};

#endif