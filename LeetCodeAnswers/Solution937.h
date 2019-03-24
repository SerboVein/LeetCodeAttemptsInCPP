#pragma once
#ifndef SOLUTION937_H
#define SOLUTION937_H

#include <string>
#include <vector>
#include <algorithm>
using namespace std;


/*
	really really beautiful hacking here, designed a simple sorter to sort the entire logs vector. 
	to lexicographically sort the letter-logs is very easy: use the default string compare. 
	but to sort digit-logs, we have to use their index in the string. but in a compare function, there is no clue of their index
	so i encoded the index into the last pos of the log string, and used it in the sort function and later pop it out!!
	it worked very smoothly with good performance !!! 
*/

class Solution937 {
public:
	static bool logcompare(string& A, string& B)
	{
		int Astart = 0;
		int Bstart = 0;
		for (int i = 0; i < A.size(); i++)
			if (A[i] == ' ')
			{
				Astart = i + 1;
				break;
			}
		for (int i = 0; i < B.size(); i++)
			if (B[i] == ' ')
			{
				Bstart = i + 1;
				break;
			}

		bool isAdigitThanStr = A[Astart] >= '0' && A[Astart] <= '9';
		bool isBdigitThanStr = B[Bstart] >= '0' && B[Bstart] <= '9';

		if (isAdigitThanStr && isBdigitThanStr)
			return A[A.size() - 1] < B[B.size() - 1];

		if (!isAdigitThanStr && !isBdigitThanStr)
			return A.substr(Astart, A.size() - Astart) < B.substr(Bstart, B.size() - Bstart);

		return isBdigitThanStr;
	}

	vector<string> reorderLogFiles(vector<string>& logs) {
		vector<string> reorderedLogs;
		for (int i = 0; i < logs.size(); i++)
			logs[i].push_back(i);
		sort(logs.begin(), logs.end(), logcompare);

		for (int i = 0; i < logs.size(); i++)
			logs[i].pop_back();

		return logs;
	}
};


#endif