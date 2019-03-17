#pragma once
#ifndef SOLUTION926_H
#define SOLUTION926_H

#include <string>
using namespace std;


/*
	the key of solving this problem is to observe that : 
		the 0's and 1's boundry (a series of 0s followed by a series of 1s) is a finite small number of S.size()
	so we iterate over the entire range of boundries to solve this problem.
	and utilize the already computed Flips of previous position of the boundry( may be this is dynamic programmig?) 
	to further reduce computation time. 
*/

class Solution926 {
public:
	int minFlipsMonoIncr(string S) {
		int minFlips = 0;

		for (int i = 0; i < S.size(); i++)
			if (S[i] != '1')
				minFlips++;

		int FlipsNow = minFlips;
		for (int iBoundry = 1; iBoundry <= S.size(); iBoundry++)
		{
			if (S[iBoundry - 1] == '0')
			{
				FlipsNow--;
				if (FlipsNow < minFlips)
					minFlips = FlipsNow;
			}
			else
				FlipsNow++;
		}

		return minFlips;
	}
};


#endif