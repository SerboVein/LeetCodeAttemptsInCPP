#pragma once
#ifndef SOLUTION506_H
#define SOLUTION506_H

#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution506 {
public:
	vector<string> findRelativeRanks(const vector<int>& nums) {
		map<int, int,greater<int>> relativeRanks;
		for (int i = 0; i < nums.size(); i++)
			relativeRanks[nums[i]] = i;

		vector<string> ans(nums.size());
		vector<string> medals = { "Gold Medal", "Silver Medal", "Bronze Medal" };
		int i = 0;
		for (auto iter = relativeRanks.begin(); iter != relativeRanks.end(); iter++)
		{
			if (i <= 2)
				ans[iter->second] = medals[i];
			else
				ans[iter->second] = to_string(i + 1);

			i++;
		}

		return ans;
	}
};

#endif