#pragma once
#ifndef SOLUTION447_H
#define SOLUTION447_H

#include <vector>
#include <math.h>
using namespace std;
#include <unordered_map>

class Solution447 {
public:
	inline int calcDistSQR(vector<int>& p1, vector<int>& p2)
	{
		return pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2);
	}

	inline int factorial(int num)
	{
		int result = 1;

		while (num > 1)
			result *= num--;

		return result;
	}

	int numberOfBoomerangs(vector<vector<int>> points) {
		int ans = 0;
		int *cache = new int[points.size()*points.size()];
		for (int i = 0; i < points.size(); i++)
		{
			unordered_map <int, int> distHist;
			for (int j = 0; j < i; j++)
				distHist[cache[j*points.size()+ i]]++;

			for (int j = i + 1; j < points.size(); j++)
			{
				int dist = calcDistSQR(points[i], points[j]);
				cache[i*points.size()+ j] = dist;
				distHist[dist]++;
			}

			for (auto &Hdist : distHist)
			{
				if (Hdist.second > 1)
					ans += Hdist.second * (Hdist.second - 1);
			}
		}
		return ans;
	}
};

#endif