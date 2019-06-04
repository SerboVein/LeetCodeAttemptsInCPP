#pragma once
#ifndef SOLUTION283_H
#define SOLUTION283_H
#include <vector>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int j = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 0)
				continue;
			if (i != j)
				nums[j] = nums[i];
			j++;
		}

		while (j < nums.size())
			nums[j++] = 0;

	}
};

#endif