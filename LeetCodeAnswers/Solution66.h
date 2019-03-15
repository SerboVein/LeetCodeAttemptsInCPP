#pragma once
#ifndef SOLUTION66_H
#define SOLUTION66_H
#include <vector>
using namespace std;

class Solution66 {
public:
	vector<int> plusOne(vector<int>& digits) {
		if (digits.empty())
			return digits;

		int overflow = 1;

		for (int i = digits.size() - 1; i >= 0; i--)
		{
			overflow = (digits[i] + overflow) / 10;
			digits[i] = (digits[i] + overflow) % 10;
			if (!overflow)
				break;
		}

		if (overflow)
			digits.insert(digits.begin(), 1);

		return digits;
	}
};


#endif