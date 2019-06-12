#pragma once
#ifndef SOLUTION982_H
#define SOLUTION982_H
#include "commonHeader.h"

//quite hard on the combinations and arrangements mathematical thoughts ,almost done, but a few points need clarification. 

//requires further optimization. 
class Solution982 {
public:

	int countTriplets(vector<int>& A) {
		int count = 0;

		for (int i = 0; i < A.size(); i++)
		{
			if (A[i] == 0)
			{
				count += 1 + (A.size() - 1) * 3;
				//continue;
			}
			for (int j = i + 1; j < A.size(); j++)
			{
				if ((A[i] & A[j]) == 0)
				{
					if (A[i] == 0 && A[j] == 0)
						;
					else if (A[i] == 0 || A[j] == 0)
						count += 3;
					else
						count += 6;
					//count += 3 * A.size();
					//continue;
					count += 6 * (A.size() - j - 1);
					continue;
				}
				for (int k = j + 1; k < A.size(); k++)
					if ((A[i] & A[j] & A[k]) == 0)
						count += 6;
			}
		}
		return count;
	}
};

#endif