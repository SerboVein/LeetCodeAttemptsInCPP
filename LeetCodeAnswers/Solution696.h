#pragma once
#ifndef SOLUTION696_H
#define SOLUTION696_H

#include <string>

using namespace std;


class Solution696__ {
public:

	int countBinarySubstrings(string s) {
		int cnt = 0;
		int cntConseqNow = 1;
		int cntConseqPrev = 0;

		for (int i = 1; i < s.size(); i++)
		{
			if (s[i] != s[i - 1])
			{
				cnt += min(cntConseqNow, cntConseqPrev);
				cntConseqPrev = cntConseqNow;
				cntConseqNow = 1;
			}
			else
				cntConseqNow++;

		}

		return cnt + min(cntConseqNow, cntConseqPrev);
	}
};

// this solution exceeds the time limit, the above is a better solution. 
class Solution696 {
public:
	bool checkValidStr(string &s, int l, int r)
	{
		int cntZeros = 0;
		int cntOnes = 0;
		bool isSwitched = false;
		for (int i = l; i <= r; i++)
		{
			if (s[i] != s[l])
				isSwitched = true;
			else if (isSwitched)
				return false;

			if (s[i] == '0')
				cntZeros++;
			else
				cntOnes++;
		}

		return cntZeros == cntOnes;
	}

	int countBinarySubstrings(string s) {
		int cnt = 0;

		for (int l = 0; l < s.size() - 1; l++)
			for (int r = l + 1; r < s.size(); r += 2)
				if (checkValidStr(s, l, r))
				{
					cnt++;
					break;
				}

		return cnt;
	}
};

#endif