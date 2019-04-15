#pragma once
#ifndef SOLUTION697_H
#define SOLUTION697_H

#include <unordered_map>
#include <vector>

using namespace std;


class Solution697 {
public:
	int findShortestSubArray(const vector<int>& nums) {
		unordered_map<int, int> hist;
		unordered_map<int, int> startPos;

		int lastIndexMaxFreqNum = nums.size();
		int MaxFreq = 0;
		int MaxFreqNum = -1;

		for (int i = 0; i < nums.size(); i++)
		{
			if (!hist[nums[i]])
				startPos[nums[i]] = i;
			hist[nums[i]]++;
			if (MaxFreqNum == -1 || hist[nums[i]] > MaxFreq || (hist[nums[i]] == MaxFreq && lastIndexMaxFreqNum - startPos[MaxFreqNum] > i - startPos[nums[i]]))
			{
				MaxFreq = hist[nums[i]];
				MaxFreqNum = nums[i];
				lastIndexMaxFreqNum = i;
			}
		}

		return lastIndexMaxFreqNum - startPos[MaxFreqNum] + 1;

	}
};

#endif