#pragma once
#ifndef SOLUTION1012_H
#define SOLUTION1012_H

class Solution1012 {
public:
	int bitwiseComplement(int N) {
		unsigned int  mask = 1 << 31;
		bool isFlipping = false;

		while (mask)
		{
			if (isFlipping)
				N ^= mask;
			else if ((N & mask) == mask)
			{
				N ^= mask;
				isFlipping = true;
			}
			mask >>= 1;
		}

		return N;
	}
};


#endif