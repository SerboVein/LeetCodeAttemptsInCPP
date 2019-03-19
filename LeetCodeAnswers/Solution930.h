#pragma once
#ifndef SOLUTION930_H
#define SOLUTION930_H

#include <vector>
using namespace std;

class Solution930 {
public:
	class Solution {
	public:

		int numSubarraysWithSum(vector<int>& A, int S) {
			int numSubarray = 0;
			int firstValidEnd = 0;

			for (int start = 0; start < A.size(); start++)
			{
				int sums = 0;
				for (int end = firstValidEnd; end < A.size(); end++)
				{
					sums += A[end];
					if (sums == S)
					{
						numSubarray++;
						if (A[end] == 1)
							firstValidEnd = end;
					}
					else if (sums > S)
						break;
				}
			}
			return numSubarray;
		}
	};
};

#endif