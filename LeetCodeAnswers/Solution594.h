#pragma once
#ifndef SOLUTION594_H
#define SOLUTION594_H
#include <vector>
using namespace std;

class Solution594 {
public:
	int findLHS(const vector<int>& nums) {
		vector<vector<int>> subsequences;
		int maxLen = 0;

		for (auto &n : nums)
		{
			bool anyHit = false;
			for (auto &limits : subsequences)
			{
				if (limits.empty())
					continue;

				if (limits[0] <= n && limits[1] >= n)
				{
					limits[2]++;

					if (limits[0] != limits[1])
						if (limits[2] > maxLen)
							maxLen = limits[2];

					anyHit = true;
				}
				else if (abs(limits[0] - n) == 1 && limits[0] == limits[1])
				{
					vector<int> fork(limits);
					if (n > fork[0])
						fork[1] = n;
					else
						fork[0] = n;

					bool alreadyExists = false;
					for (auto &checkLimit : subsequences)
					{
						if (checkLimit[0] == fork[0] &&
							checkLimit[1] == fork[1])
						{
							alreadyExists = true;
							break;
						}
					}

					if (!alreadyExists)
					{
						fork[2]++;
						if (fork[2] > maxLen)
							maxLen = fork[2];

						subsequences.push_back(fork);
						anyHit = true;

					}
				}
			}

			if (!anyHit)
				subsequences.push_back({ n,n,1 });
		}

		return maxLen;
	}
};


#endif