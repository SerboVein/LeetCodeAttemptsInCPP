#pragma once
#ifndef SOLUTION13_H
#define SOLUTION13_H

#include <map>
using namespace std;

class Solution13 {
public:
	int romanToInt(string s) {
		//vector<string> notes = {"X","IV"};
		map<string, int> romanValues = { {"IV",4},{"IX" , 9},{"XL" , 40},{"XC" , 90},{"CD" , 400},{"CM" , 900},{"I" , 1},{"V" , 5},{"X" , 10},{"L" , 50},{"C" , 100},{"D" , 500},{"M" , 1000 } };
		int result = 0;
		for (int i = 0; i < s.size(); i++)
		{
			int compareSize = s.size() - i >= 2 ? 2 : 1;
			auto iter = romanValues.find(s.substr(i, compareSize));
			if (iter != romanValues.end())
			{
				i += compareSize == 2 ? 1 : 0;
				result += iter->second;
			}
			else
				result += romanValues.find(s.substr(i, 1))->second;

		}

		return result;
	}
};
#endif