#pragma once
#ifndef SOLUTION720_H
#define SOLUTION720_H
#include "commonHeader.h"

class Solution720 {
public:
	string longestWord(vector<string> words) {
		sort(words.begin(), words.end());
		return words[0];
	}
};

#endif