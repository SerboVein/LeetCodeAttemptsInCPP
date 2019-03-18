#pragma once
#ifndef SOLUTION1002_H
#define SOLUTION1002_H

#include <vector>
#include <string>
using namespace std;

class Solution1002 {
public:
	vector<string> commonChars(vector<string>& A) {
		string common = A[0];
		for (auto str : A)
		{
			for (int i = 0; i < (int)common.size(); i++)
			{
				int pos = str.find(common[i], 0);
				if (pos != -1)
					str[pos] = '-';
				else
				{
					common.erase(i, 1);
					i--;
				}
			}
		}

		vector<string> result;
		for (auto c : common)
		{
			string cc = { c };
			result.push_back(cc);
		}
		return result;
	}
};

#endif