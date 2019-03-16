#pragma once
#ifndef SOLUTION228_H
#define SOLUTION228_H

#include <vector>
#include <string>
using namespace std;

class Solution228 {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> ranges;
		if (nums.size() == 0)
			return ranges;

		int rangeStart = nums[0];

		for (int i = 1; i <= nums.size(); i++)
		{
			if (i == nums.size() || nums[i] > nums[i - 1] + 1)
			{
				if (nums[i - 1] != rangeStart)
					ranges.push_back(
						to_string(rangeStart) + "->" + to_string(nums[i - 1]));
				else
					ranges.push_back(to_string(rangeStart));

				if (i != nums.size())
					rangeStart = nums[i];
			}
		}

		return ranges;
	}
};


#endif