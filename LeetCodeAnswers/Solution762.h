#pragma once
#ifndef SOLUTION762_H
#define SOLUTION762_H


#include <vector>
#include <iostream>

class Solution762 {
public:
	void generatePrimeHashTable()
	{
		std::cout << "{";
		for (int i = 0; i < 33; i++)
		{
			std::cout << checkPrime(i) ? 1 : 0;
			std::cout << ",";
		}
		std::cout << "}" << std::endl;
	}

	inline static bool checkPrime(int num)
	{

		if (num == 1)
			return false;
		if (num == 2)
			return true;

		int j = 2;

		for (; j <= sqrt(num); j++)
			if (num % j == 0)
				return false;

		return true;
	}

	int countPrimeSetBits(int L, int R) {
		vector<int> primeHashTable(32, -1);
		int nPrimeBitNumCount = 0;
		int nSmall = 0;

		for (int i = L; i <= R; i++)
		{
			int thisNum = i;
			int nPrimes = 0;

			while (thisNum)
			{
				if (thisNum & 1)
					nPrimes++;
				thisNum >>= 1;
			}

			int quickCheck = primeHashTable[nPrimes];

			if (quickCheck == -1)
			{
				primeHashTable[nPrimes] = checkPrime(nPrimes) ? 1 : 0;
				nPrimeBitNumCount += primeHashTable[nPrimes];
			}
			else
				nPrimeBitNumCount += quickCheck;
		}

		return nPrimeBitNumCount;
	}
};

#endif