#pragma once
#ifndef SOLUTION453_H
#define SOLUTION453_H
#include "commonHeader.h"

class Solution453 {
public:
	/*int minMoves(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		int movesCnt = 0;
		for(int i = 0 ;i + 1< nums.size() ;i++)
			movesCnt += (nums.size() - i - 1) * (nums[i+1] - nums[i]);

		return movesCnt;
	}*/

	int minMoves(vector<int>& nums) {
		int min_v = *min_element(nums.begin(), nums.end()), res = 0;  //what is this shit??? 
		for (int I : nums)
			res += I - min_v;
		return res;
	}

};



// deprecated and bad codes here. 
/*
class Solution453 {
public:
	bool checkEqual(vector<int>& nums)
	{
		for (int i = 0; i + 1 < nums.size(); i++)
			if (nums[i] != nums[i + 1])
				return false;

		return true;
	}

    
    int minMoves(vector<int>& nums) {
        int min_v = *min_element(nums.begin(),nums.end()),res = 0;
        for(int I : nums)
            res += I-min_v;
        return res;
    }
    
};

	int minMoves(vector<int>& nums) {
		int iMax = -1;
		bool isMaxSet = false;
		bool isMinSet = false;
		long max = 0;
		long min = 9999;
		bool isEqual = true;

		for (int i = 0; i < nums.size(); i++)
		{
			if (i > 0 && nums[i] != nums[i - 1])
				isEqual = false;

			if (nums[i] > max || !isMaxSet)
			{
				isMaxSet = true;
				max = nums[i];
				iMax = i;
			}

			if (nums[i] < min || !isMinSet)
			{
				min = nums[i];
				isMinSet = true;
			}
		}

		int cntMoves = 0;
		while (!isEqual)
		{
			long curMoves = max - min;
			cntMoves += curMoves;

			isEqual = true;
			int iMaxNext = iMax;
			bool isMinSet = false;
			min = 9999;

			for (int i = 0; i < nums.size(); i++)
			{
				if (i != iMax)
				{
					nums[i] += curMoves;
					if (nums[i] > max)
					{
						iMaxNext = i;
						max = nums[i];
					}
				}
				if (i > 0 && nums[i] != nums[i - 1])
					isEqual = false;
				if (nums[i] < min || !isMinSet)
				{
					min = nums[i];
					isMinSet = true;
				}

			}

			iMax = iMaxNext;
		}

		return cntMoves;
	}
};
*/
#endif