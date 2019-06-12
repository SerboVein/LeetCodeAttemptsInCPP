#pragma once
#ifndef SOLUTION819_H
#define SOLUTION819_H
#include "commonHeader.h"

class Solution819 {
public:
	string mostCommonWord(string paragraph, vector<string>& banned) {
		transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
		string word;
		int max = 0;
		paragraph.push_back('.');
		string commonword = "";
		unordered_map<string, int> hist;
		int iWordSt = 0;
		for (int i = 0; i < paragraph.size(); i++)
		{
			if (!(paragraph[i] >= 'a' && paragraph[i] <= 'z'))
			{
				if (i - iWordSt > 0)
				{
					word = paragraph.substr(iWordSt, i - iWordSt);
					if (find(banned.begin(), banned.end(), word) == banned.end())
					{
						hist[word]++;
						if (hist[word] > max)
						{
							max = hist[word];
							commonword = word;
						}
					}

				}
				iWordSt = i + 1;
				break;
			}

		}
		return commonword;
	}
};

#endif