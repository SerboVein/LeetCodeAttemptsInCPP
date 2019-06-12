#pragma once
#ifndef SOLUTION984_H
#define SOLUTION984_H
#include "commonHeader.h"

class Solution984 {
public:
	string strWithout3a3b(int A, int B) {
		bool isAbiggerThanB = false;
		int nGroupCnt = 0;
		int nLesser = 0;
		int nMorer = 0;
		if (A > B)
		{
			nMorer = A;
			nLesser = B;
			nGroupCnt = A / 2;
			isAbiggerThanB = true;
		}
		else
		{
			nMorer = B;
			nGroupCnt = B / 2;
			nLesser = A;
		}

		string ans = "";
		int i = 0;
		while (nMorer > 0 || nLesser > 0)
		{
			if (nMorer >= 2)
			{
				ans += isAbiggerThanB ? "aa" : "bb";
				nMorer -= 2;
			}
			else if (nMorer == 1)
			{
				ans += isAbiggerThanB ? "a" : "b";
				nMorer--;
			}
			if (nLesser > 0)
			{
				ans += isAbiggerThanB ? "b" : "a";
				nLesser--;

				if (nLesser > 0 && nLesser >= nGroupCnt - i)
				{
					ans += isAbiggerThanB ? "b" : "a";
					nLesser--;
				}
			}
			i++;
			//nGroupCnt++;
		}

		return ans;
	}
};

#endif