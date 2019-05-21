#pragma once
#ifndef SOLUTION20_H
#define SOLUTION20_H

#include <vector>
#include <string>
using namespace std;

class Solution20 {
public:
	bool isValid(string s) {
		vector<char> stack = {};

		for (auto &c : s)
		{
			switch (c)
			{
			case '(':
			case '[':
			case '{':
				stack.push_back(c);
				//push into stack
				break;
			default:
				if (stack.empty())
					return false;
				switch (c)
				{
				case ')':
					if (stack.back() != '(')
						return false;
					break;
				case ']':
					if (stack.back() != '[')
						return false;
					break;
				case '}':
					if (stack.back() != '{')
						return false;
					break;
					stack.pop_back();
				}

			}
		}

		return true;
	}
};

#endif