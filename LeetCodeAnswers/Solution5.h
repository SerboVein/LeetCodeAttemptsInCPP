#pragma once
#ifndef SOLUTION5_H
#define SOLUTION5_H
#include <string>
#include <vector>

using namespace std;
class Solution5 {
public:
	string longestPalindrome(string s) {
		int iLeftMidlongest = -1;
		int maxLen = -1;

		for (int i = 0; i < s.size() * 2; i++)
		{
			int iLeftMid, iRightMid;
			if (i % 2 == 0)
			{
				iLeftMid = iRightMid = i / 2;
			}
			else
			{
				iLeftMid = i / 2 + 1;
				iRightMid = i / 2;
			}

			int oneSideLen = 0;

			for (; oneSideLen + iRightMid < s.size() && iLeftMid - oneSideLen >= 0; oneSideLen++)
			{
				if (s[iLeftMid - oneSideLen] != s[oneSideLen + iRightMid])
					break;
			}

			int actualLen = 2 * (oneSideLen - 1) + (iLeftMid == iRightMid ? 1 : 0);
			if (actualLen > maxLen)
			{
				maxLen = actualLen;
				iLeftMidlongest = iLeftMid;
			}

		}
		if (maxLen > 0)
			return s.substr(iLeftMidlongest - maxLen / 2, maxLen);
		else
			return "";
	}
};


#endif