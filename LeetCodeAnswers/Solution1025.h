#pragma once
#ifndef SOLUTION1025_H
#define SOLUTION1025_H
#include <vector>
using namespace std;

class Solution1025 {
public:
	bool searchWin(vector<int> &cache, int num)
	{
		switch (num)
		{
		case 1:
			return false;
		case 2:
			return true;
		case 3:
			return false;
		}

		if (cache[num])
			return cache[num] == 1; //1 for win, 2 for lose.

		for (int i = num / 2; i >= 1; i--)
		{
			if (num % i == 0)
				if (!searchWin(cache, num - i))
				{
					cache[num] = 1;
					return true;
				}
		}

		cache[num] = 2;
		return false;
	}

	bool divisorGame(int N) {
		vector<int> cache(N + 1, 0);
		return searchWin(cache, N);
	}

private:
};

#endif