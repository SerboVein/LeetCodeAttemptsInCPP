#pragma once
#ifndef SOLUTION295_H
#define SOLUTION295_H
#include <list>
using namespace std;

class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {
		listsize = 0;
		nums.clear();
	}

	void addNum(int num) {
		int i = 0;
		auto iter = nums.begin();
		while (iter != nums.end())
		{
			if (*iter > num)
				break;
			iter++;
		}
		nums.insert(iter, num);
		listsize++;
	}

	double findMedian() {
		int i = 0;
		auto iter = nums.begin();
		
		while (i < listsize)
		{
			if (i == listsize / 2)
			{
				if (listsize % 2 == 0)
					return (double)(*iter + *(--iter)) / 2;
				else
					return *iter;
			}
			i++;
			iter++;
		}
		return 0.0; //never happens
	}

private:
	int listsize;
	list<int> nums;

};



#endif