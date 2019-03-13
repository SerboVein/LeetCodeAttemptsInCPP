#pragma once
#ifndef SOLUTION930_H
#define SOLUTION930_H

#include <vector>
using namespace std;

class Solution930 {
public:
	int calcSubarraySum(vector<int> & A, int start, int end)
	{
		int sum = 0;
		for (int i = start; i <= end; i++)
			sum += A[i];

		return sum;
	}

	vector<int> BuildScissorVec(vector<int> & A)
	{
		int thisZeroCount = 0;
		vector<int> scissorVec;
		for (auto a : A)
		{
			if (a == 1)
			{
				scissorVec.push_back(thisZeroCount);
				thisZeroCount = 0;
			}
			else
				thisZeroCount++;
		}
		scissorVec.push_back(thisZeroCount);

	}

	int numSubarraysWithSum(vector<int>& A, int S) {
		int numSubarray = 0;
		for (int start = 0; start < A.size(); start++)
			for (int end = start; end < A.size(); end++)
				if (calcSubarraySum(A, start, end) == S)
					numSubarray++;

		return numSubarray;
	}
};

#endif