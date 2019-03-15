#pragma once
#ifndef SOLUTION67_H
#define SOLUTION67

#include <string>
using namespace std;

class Solution67 {
public:
	string addBinary(string a, string b) {
		string answer = "";
		int overflow = 0;
		int i, j;
		for (i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; i--, j--)
		{
			int thisDigit = overflow;
			if (i >= 0)
				thisDigit += a[i] - '0';
			if (j >= 0)
				thisDigit += b[j] - '0';

			overflow = thisDigit / 2;
			answer.insert(0, 1, thisDigit % 2 + '0');
		}

		if (overflow)
			answer.insert(0, 1, '1');

		return answer;
	}
};

#endif