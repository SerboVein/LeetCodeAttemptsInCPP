#pragma once
#ifndef SOLUTION322_H
#define SOLUTION322_H
#include <queue>
#include <vector>

using namespace std;

class Solution322 {
public:
	int findAmount(vector<int>& coins, int subAmount)
	{
		if ((*cache)[subAmount] != -1)
			return (*cache)[subAmount];

		if (subAmount == 0)
			return 0;

		int MinCost = 9999;
		for (auto &c : coins)
		{
			if (c > subAmount)
				continue;
			int curCost = findAmount(coins, subAmount - c) + 1;
			if (curCost < MinCost)
				MinCost = curCost;
		}

		(*cache)[subAmount] = MinCost;

		return MinCost;
	}

	int coinChange(vector<int>& coins, int amount) {
		if (amount == 0)
			return 0;

		cache = new vector<int>(amount + 1,-1);
		int MinCost = findAmount(coins, amount);
		return MinCost != 9999 ? MinCost : -1;
	}

private:
	vector<int> *cache;
};

//class Solution322 {
//public:
//	int findAmount(vector<int>& coins, int amount, int iCoin, int subAmount)
//	{
//		if (iCoin == coins.size())
//			return -1;
//
//		for (int i = 0; true; i++)
//		{
//			int curAmount = subAmount + i * coins[iCoin];
//			if (curAmount == amount)
//				return i;
//			else if (curAmount < amount)
//			{
//				int ret =
//					findAmount(coins, amount, iCoin + 1, curAmount);
//				if (ret != -1)
//					return ret + i;
//			}
//			else
//				break;
//		}
//
//		return -1;
//	}
//
//	int coinChange(vector<int>& coins, int amount) {
//		if (amount == 0)
//			return 0;
//
//		return findAmount(coins, amount, 0, 0);
//	}
//}; 

#endif