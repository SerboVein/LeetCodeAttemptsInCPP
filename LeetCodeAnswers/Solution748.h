#pragma once
#ifndef SOLUTION748_H
#define SOLUTION748_H

#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution748 {
public:
	string shortestCompletingWord(string licensePlate, vector<string>& words) {
		unordered_map <char, int> actualLP;
		vector<vector<string>> words_neworder = {};
		for (int i = 0; i <= 15; i++)
		{
			vector<string> empty = {};
			words_neworder.push_back(empty);
		}

		for (auto c : licensePlate)
			if (tolower(c) >= 'a' && tolower(c) <= 'z')
				actualLP[tolower(c)]++;


		int bestLength = 16;
		string bestWord = "";

		for (auto word : words)
		{
			bool isGoodWord = true;
			unordered_map <char, int> cpActualLP(actualLP);
			for (auto c : word)
			{
				if (cpActualLP.find(tolower(c)) != cpActualLP.end())
					cpActualLP[tolower(c)]--;
			}

			for (auto iter = cpActualLP.begin(); iter != cpActualLP.end(); iter++)
				if (iter->second > 0)
				{
					isGoodWord = false;
					break;
				}

			if (isGoodWord)
			{
				if (word.size() < bestLength)
				{
					bestLength = word.size();
					bestWord = word;
				}
			}
		}

		return bestWord;
	}
};

#endif