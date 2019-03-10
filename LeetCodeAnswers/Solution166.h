#pragma once
#ifndef SOLUTION166_H
#define SOLUTION166_H
#include <string>
#include <vector>

using namespace std;
class Solution166 {
public:
	string fractionToDecimal(int numerator, int denominator) {
		std::vector<unsigned long int> remainders;
		string result;
		if ((numerator > 0 && denominator < 0) ||
			(numerator < 0 && denominator > 0))
			result = "-";

		long dummy = numerator;
		unsigned long int absnumerator = abs(dummy);
		dummy = denominator;
		unsigned long int absdenominator = abs(dummy);


		result += to_string(absnumerator / absdenominator);
		unsigned long int remainder = absnumerator - absnumerator / absdenominator * absdenominator;
		if (remainder)
			result += '.';
		while(remainder)
		{
			remainder *= 10;
			auto iter = std::find(remainders.begin(), remainders.end(), remainder);
			if (iter != remainders.end())
			{
				int pos = iter - remainders.begin();
				auto resultIter = std::find(result.begin(), result.end(), '.') + pos + 1;
				result.insert(resultIter,1, '(');
				result.push_back(')');
				break;
			}
			remainders.push_back(remainder);
			int newDigit = remainder / absdenominator;
			result += to_string(newDigit);
			remainder = remainder - remainder / absdenominator * absdenominator;
		}
		return result;
	}
};


#endif