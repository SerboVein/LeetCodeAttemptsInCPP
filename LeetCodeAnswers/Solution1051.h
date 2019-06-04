#pragma once
#ifndef SOLUTION1051_H
#define SOLUTION1051_H
#include <vector>
#include <algorithm>


class Solution1051 {
public:
	int heightChecker(std::vector<int>& heights) {
		std::vector<int> copy(heights);
		std::sort(copy.begin(), copy.end());

		int nDiffs = 0;
		for (int i = 0; i < copy.size(); i++)
			if (copy[i] != heights[i])
				nDiffs++;

		return nDiffs;
	}
};

#endif