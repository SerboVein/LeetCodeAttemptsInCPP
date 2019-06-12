#pragma once
#ifndef SOLUTION413_H
#define SOLUTION413_H
#include "commonHeader.h"

class Solution413 {
public:
	int calcCombinations(int mother, int child)
	{
		if (child > mother / 2)
			child = mother - child;

		int nominator = 1, denominator = 1;
		for (int i = 0; i < child; i++)
		{
			denominator *= (mother - i);
			nominator *= 1 + i;
		}

		return denominator / nominator;
	}

	int convertLenToNums(int arithmeticLen)
	{
		int numbers = 1;
		for (int i = 3; i < arithmeticLen; i++)
			numbers += arithmeticLen - i + 1;

		return numbers;
	}

	int numberOfArithmeticSlices(vector<int>& A) {
		if (A.size() < 3)
			return 0;

		int ans = 0;
		int curArithmeticLen = 0;
		for (int i = 1; i + 1 < A.size(); i++)
		{
			if (A[i] - A[i - 1] == A[i + 1] - A[i])
			{
				if (curArithmeticLen == 0)
					curArithmeticLen = 3;
				else
					curArithmeticLen++;
			}
			else if (curArithmeticLen)
				ans += convertLenToNums(curArithmeticLen);

		}

		if (curArithmeticLen)
			ans += convertLenToNums(curArithmeticLen);

		return ans;
	}
};


#endif