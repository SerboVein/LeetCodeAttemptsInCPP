#pragma once
#ifndef SOLUTION977_H
#define SOLUTION977
#include <vector>
using namespace std;


class Solution977 {
public:
	int getFake(vector<int> &A, int i) {
		if (i < 0)
			return -20000;
		else if (i >= A.size())
			return 20000;

		return A[i];
	}
	vector<int> sortedSquares(vector<int>& A) {
		vector<int> result = {};

		int iCenter = 0;
		for (int i = 0; i < A.size(); i++)
			if (getFake(A, i) <= 0 &&
				getFake(A, i + 1) >= 0)
			{
				iCenter = abs(getFake(A, i)) < abs(getFake(A, i + 1)) ? i : i + 1;
				break;
			}
		result.push_back(pow(A[iCenter], 2));
		int iLeft = iCenter - 1;
		int iRight = iCenter + 1;
		while (iLeft >= 0 || iRight < A.size())
		{
			int FinalVal = 0;
			int LeftVal = abs(getFake(A, iLeft));
			int RightVal = abs(getFake(A, iRight));
			if (LeftVal > RightVal)
			{
				FinalVal = RightVal;
				iRight++;
			}
			else
			{
				FinalVal = LeftVal;
				iLeft--;
			}
			result.push_back(pow(FinalVal, 2));
		}

		return result;
	}
};

#endif