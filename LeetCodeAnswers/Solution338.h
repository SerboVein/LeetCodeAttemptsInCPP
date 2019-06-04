#pragma once
#ifndef SOLUTION338_H
#define SOLUTION338_H
#include <vector>
using namespace std;

class Solution338 {
public:
	
	vector<int> countBits(int num) {
		vector<int> ans(num + 1, -1);
		ans[0] = 0; ans[1] = 1; ans[2] = 1;
		int key = 2;
		for (int i = 3; i <= num; i++)
		{
			if (i < key * 2)
			{
				ans[i] = ans[i - key] + 1;
			}
			else
			{
				key *= 2;
				ans[i] = 1;
			}
		}
		return ans;
	}

private:
};

#endif