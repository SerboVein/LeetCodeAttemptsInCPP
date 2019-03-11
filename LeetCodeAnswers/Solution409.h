#pragma once
#ifndef SOLUTION409_H
#define SOLUTION409_H

#include <string>
using namespace std;


class Solution409 {
public:
	int longestPalindrome(string s) {
		int nPairs = 0;

		for (int i = 0; i < (int)s.size() - 1; i++)
		{
			for (int j = i + 1; j < s.size(); j++)
			{
				if (s[i] == s[j])
				{
					nPairs++;
					s.erase(j, 1);
					s.erase(i, 1);
					i--;
					break;
				}
			}
		}

		return nPairs * 2 + (s.size() ? 1 : 0);
	}
};

#endif
