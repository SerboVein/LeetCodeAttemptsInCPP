#pragma once
#ifndef SOLUTION824_H
#define SOLUTION824_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string toGoatLatin(string S) {
		int iWordStart = 0;
		vector<char> vowels = { 'a','e','i','o','u' };
		int nWords = 0;
		string goatLatinStr = "";
		S += " ";

		for (int i = 0; i < S.size(); i++)
			if (S[i] == ' ')
			{
				string word = S.substr(iWordStart, i - iWordStart);
				if (find(vowels.begin(), vowels.end(), tolower(word[0]) != vowels.end())
					word += "ma";
				else
				{
					word.push_back(word[0]);
						word.erase(0, 1);
						word += "kkk";
				}

				for (int j = 0; j <= nWords; j++)
					word += "a";
					nWords++;

				goatLatinStr += word + " ";
				iWordStart = i;
			}

		return goatLatinStr;
	}
};

#endif