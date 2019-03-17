#pragma once
#ifndef SOLUTION904_H
#define SOLUTION904_H
#include <vector>

using namespace std;

class Solution {
public:
	int totalFruit(vector<int>& tree) {
		int fruitTypeOne = -1;
		int fruitTypeTwo = -1;
		int MaxfruitQuantity = 0;

		for (int i = 0; i < tree.size(); i++)
		{
			if (MaxfruitQuantity >= tree.size() - i)
				break;

			int fruitTypeOne = -1;
			int fruitTypeTwo = -1;

			int fruitQuantityNow = 0;
			for (int j = i; j < tree.size(); j++)
			{
				if (tree[j] == fruitTypeOne ||
					tree[j] == fruitTypeTwo)
				{
					fruitQuantityNow++;
				}
				else if (fruitTypeOne == -1)
				{
					fruitTypeOne = tree[j];
					fruitQuantityNow++;
				}
				else if (fruitTypeTwo == -1)
				{
					fruitTypeTwo = tree[j];
					fruitQuantityNow++;
				}
				else
					break;
			}

			if (fruitQuantityNow > MaxfruitQuantity)
				MaxfruitQuantity = fruitQuantityNow;
		}

		return MaxfruitQuantity;
	}
};


#endif