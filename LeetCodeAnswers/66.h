#pragma once
#include <vector>
using namespace std;

class Solution66{
public:
	vector<int> plusOne(vector<int>& digits) {
		if (digits.empty())
			return digits;

		int overflow = 1;

		for (int i = digits.size() - 1; i >= 0; i--)
		{
			digits[i] = (digits[i] + overflow) % 10;
			overflow = (digits[i] + overflow) / 10;
			if (!overflow)
				break;
		}

		if (overflow)
			digits.insert(digits.begin(), 1);

		return digits;
	}
};
