#pragma once
#ifndef SOLUTION214_H
#define SOLUTION214_H
#include <string>
#include <vector>

using namespace std;
class Solution214 {
public:
	bool checkPalindrome(string &s, int subSize)
	{
		for (int i = 0; i < subSize / 2; i++)
			if (s[i] != s[subSize - i - 1])
				return false;

		return true;
	}
	string shortestPalindrome(string s) {
		int MaxlenOfLeftPalidrome = 1;
		for (int i = 2; i <= s.size(); i++)
			if (checkPalindrome(s,i))
				MaxlenOfLeftPalidrome = i;

		string leftPadding = "";
		for (int i = MaxlenOfLeftPalidrome; i < s.size(); i++)
			leftPadding.insert(0, 1, s[i]);

		return leftPadding + s;
	}
};

#endif
