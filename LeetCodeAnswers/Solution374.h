#pragma once
#ifndef SOLUTION374_H
#define SOLUTION374_H

class Solution374 {
public:
	int guessNumber(int n) {
		int upbound = n, lowbound = 0;
		while (true)
		{
			if (upbound - lowbound <= 3)
			{
				for (int i = lowbound; i <= upbound; i++)
					if (guess(i) == 0)
						return i;
				break;
			}
			int curGuess = (upbound + lowbound) / 2;
			switch (guess(curGuess))
			{
			case -1:
				lowbound = curGuess;
				break;
			case 1:
				upbound = curGuess;
				break;
			case 0:
				return curGuess;
			}
		}

		return -1;
	}
private:
	int guess(int n)
	{
		if (n < 6)
			return -1;
		else if (n > 6)
			return 1;
		else
			return 0;
	}

};

#endif