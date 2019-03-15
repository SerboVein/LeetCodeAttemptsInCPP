#pragma once
#ifndef SOLUTION219_H
#define SOLUTION219_H

#include <map>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution219 {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int, int> hist;
		int i;

		for (i = 0; i < nums.size() && i <= k; i++)
		{
			if (hist.count(nums[i]))
				return true;

			hist[nums[i]] = 1;
		}


		for (; i < nums.size(); i++)
		{
			hist[nums[i - k - 1]] = 0;
			if (hist.count(nums[i]) && hist[nums[i]])
				return true;

			hist[nums[i]] = 1;
		}

		return false;
	}
};

#endif