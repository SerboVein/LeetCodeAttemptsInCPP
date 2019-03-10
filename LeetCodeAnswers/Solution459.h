#pragma once
#ifndef SOLUTION459_H
#define SOLUTION459_H

#include <string>

using namespace std;

class Solution459 {
public:
	bool repeatedSubstringPattern(string s) {
		for (int nAssumeSub = 1; nAssumeSub <= s.size() / 2; nAssumeSub++)
		{
			if (s.size() % nAssumeSub != 0)
				continue;

			int i = nAssumeSub;
			for (;i < s.size(); i++)
				if (s[i] != s[i%nAssumeSub])
					break;

			if (i == s.size())
				return true;
		}
		return false;
	}
};


#endif