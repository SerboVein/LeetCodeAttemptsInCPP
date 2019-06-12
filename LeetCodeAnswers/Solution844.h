#pragma once
#ifndef SOLUTION844_H
#define SOLUTION844_H
#include "commonHeader.h"

class Solution844 {
public:

	bool backspaceCompare(string S, string T) {
		int i = S.size() - 1;
		int j = T.size() - 1;
		int Sbackspace = 0;
		int Tbackspace = 0;
		while (i >= 0 || j >= 0)
		{
			if (i >= 0)
			{
				if (S[i] == '#')
				{
					Sbackspace++;
					i--;
					continue;
				}
				else if (Sbackspace)
				{
					i--;
					Sbackspace--;
					continue;
				}
			}
			if (j >= 0)
			{
				if (T[j] == '#')
				{
					Tbackspace++;
					j--;
					continue;
				}
				else if (Tbackspace)
				{
					j--;
					Tbackspace--;
					continue;
				}
			}

			if (i <0 || j < 0 || S[i] != T[j])
				return false;
			i--; j--;
		}

		return i <= -1 && j <= -1;
	}

};

#endif