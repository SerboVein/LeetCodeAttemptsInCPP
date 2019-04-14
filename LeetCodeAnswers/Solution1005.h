#pragma once
#ifndef SOLUTION1005_H
#define SOLUTION1005_H

#include <vector>
#include <algorithm>
using namespace std;

class Solution1005 {
public:
	int largestSumAfterKNegations(vector<int>& A, int K) {
		sort(A.begin(), A.end());
		int sum = 0;
		int minPositive = 99999;
		for (int i = 0; i < A.size(); i++)
		{
			if (K)
			{
				if (A[i] < 0)
				{
					A[i] = -A[i];
					if (A[i] < minPositive)
						minPositive = A[i];
					K--;
				}
				else
				{
					if (K % 2 != 0)
					{
						if (A[i] <= minPositive)
							A[i] = -A[i];
						else
							sum -= minPositive * 2;
					}
					K = 0;
				}
			}
			sum += A[i];

		}

		return sum;
	}

};

#endif