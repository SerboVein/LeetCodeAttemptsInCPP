#pragma once
#ifndef SOLUTION507_H
#define SOLUTION507_H

class Solution507 {
public:
	bool checkPerfectNumber(int num) {
		if (num == 1)
			return false;

		int minCounterParts = 99999;
		int acc = 1;
		for (int i = 2; i <= num / 2; i++)
		{
			if (i >= minCounterParts)
				break;

			if (acc > num)
				return false;

			if (num % i == 0)
			{
				acc += i;
				acc += num / i;
				if (num / i < minCounterParts)
					minCounterParts = num / i;
			}
		}

		return acc == num;
	}
};

#endif