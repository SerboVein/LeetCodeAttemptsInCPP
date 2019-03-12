#pragma once
#ifndef SOLUTION804_H
#define SOLUTION804_H
#include <vector>
using namespace std;

class Solution804 {
public:
	int uniqueMorseRepresentations(vector<string>& words) {
		vector<string> morseMap = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
		vector<string> uniqueMorse;
		for (auto word : words)
		{
			string thisMorse = "";
			for (auto c : word)
				thisMorse += morseMap[c - 'a'];
			if (uniqueMorse.end() ==
				find(uniqueMorse.begin(), uniqueMorse.end(), thisMorse))
				uniqueMorse.push_back(thisMorse);
		}

		return uniqueMorse.size();
	}
};

#endif