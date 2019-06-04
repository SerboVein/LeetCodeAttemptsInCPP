#pragma once
#ifndef SOLUTION950_H
#define SOLUTION950_H
#include <vector>
#include <algorithm>
using namespace std;

class Solution950
{
public:
	static bool cmp(int a, int b)
	{
		return a > b;
	}

	vector<int> deckRevealedIncreasing(vector<int>& deck) {
		vector<int> buffer(deck.size() * 2);
		int left = buffer.size() - 1, right = buffer.size() - 1;
		sort(deck.begin(), deck.end(), cmp);
		bool isBegin = false;
		for (int &num : deck)
		{
			if (isBegin)
				buffer[left--] = buffer[right--];

			buffer[left--] = num;
			isBegin = true;
		}

		vector<int> ans(deck.size());
		for (int i = 0; i < ans.size(); i++)
			ans[i] = buffer[left + i + 1];

		return ans;
	}
};

#endif