#pragma once

#include <vector>
#include <iostream>
using namespace std;





void generateCombination(vector<int> &v,vector<vector<int>> &result, int st, int n,bool isMain = false)
{
	for (int i = st; i < (int)v.size() - n; i++)
	{
		if (isMain)
		{
			vector<int> combination = {};
			result.push_back(combination);
		}
		result[result.size() - 1].push_back(i);
		if(n > 1)
			generateCombination(v, result,i + 1, n - 1);
		
		if (n == 1)
			std::cout << "}";


		result[result.size() - 1].pop_back();
	}

}