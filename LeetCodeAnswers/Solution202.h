#pragma once
#ifndef SOLUTION202_H
#define SOLUTION202_H

class Solution202 {
public:
	bool isHappy(int n) {
		int cycleChecker = -1;
		int assumeCycle = 2;
		int CycleCount = 0;

		while (n != 1)
		{
			if (cycleChecker == n)
				return false;

			CycleCount++;
			if (CycleCount == assumeCycle)
			{
				cycleChecker = n;
				assumeCycle *= 2;
				CycleCount = 0;
			}


			int newN = 0;
			while (n)
			{
				newN += (n % 10) * (n % 10);
				n /= 10;
			}
			n = newN;

		}

		return true;
	}
};


#endif