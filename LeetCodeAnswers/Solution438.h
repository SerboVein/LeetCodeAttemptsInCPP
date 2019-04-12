#pragma once
#ifndef SOLUTION438_H
#define SOLUTION438_H

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution438 {
public:

	vector<int> findAnagrams(string s, string p) {
		vector<int> ans;
		if (s.size() < p.size())
			return ans;

		unordered_map<char, int> hist;

		for (auto &c : p)
			hist[c]++;

		int originalSize = hist.size();

		int zeroCount = 0;
		for (int i = 0; i < p.size(); i++)
		{
			if (hist[s[i]] == 1)
				zeroCount++;
			hist[s[i]]--;
		}
		if (zeroCount == originalSize)
			ans.push_back(0);

		for (int i = p.size(); i < s.size(); i++)
		{
			if (hist[s[i - p.size()]] == 0)
				zeroCount--;

			hist[s[i - p.size()]]++;
			if (hist[s[i]] == 1)
			{
				zeroCount++;
				if (zeroCount == originalSize)
					ans.push_back(i-p.size()+1);
			}

			hist[s[i]]--;
		}

		return ans;
	}
};

#endif