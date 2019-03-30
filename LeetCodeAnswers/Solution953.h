#pragma once
#ifndef SOLUTION953_H
#define SOLUTION953_H

#include <string>
#include <vector>
using namespace std;

class Solution953 {
public:
	static bool checkTwoWordsInOrder(string str1, string str2, vector<int> &letterRank)
	{
		for (int i = 0; i < str1.size() && i < str2.size(); i++)
		{
			int Rank1 = letterRank[str1[i] - 'a'];
			int Rank2 = letterRank[str2[i] - 'a'];

			if (Rank1 > Rank2)
				return false;
			if (Rank1 < Rank2)
				return true;
		}

		if (str1.size() > str2.size())
			return false;

		return true;
	}

	bool isAlienSorted(const vector<string>& words, string order) {
		vector<int> letterRank(order.size());
		for (int i = 0; i < order.size(); i++)
			letterRank[order[i] - 'a'] = i;

		for (int i = 0; i + 1 < words.size(); i++)
			if (!checkTwoWordsInOrder(words[i], words[i + 1], letterRank))
				return false;

		return true;
	}
};

#endif