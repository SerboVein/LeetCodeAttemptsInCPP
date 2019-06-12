#pragma once
#ifndef SOLUTION836_H
#define SOLUTION836_H

#include "commonHeader.h"

class Solution836 {
public:
	bool isPtInRectangle(int x, int y, vector<int> rect)
	{
		return x > rect[0] && x < rect[2] &&
			y > rect[3] && y < rect[1];
	}

	bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
		if (isPtInRectangle(rec1[0], rec1[1], rec2))
			return true;
		if (isPtInRectangle(rec1[0], rec1[3], rec2))
			return true;
		if (isPtInRectangle(rec1[2], rec1[3], rec2))
			return true;
		if (isPtInRectangle(rec1[2], rec1[1], rec2))
			return true;
		if (isPtInRectangle(rec2[0], rec2[1], rec1))
			return true;
		if (isPtInRectangle(rec2[0], rec2[3], rec1))
			return true;
		if (isPtInRectangle(rec2[2], rec2[3], rec1))
			return true;
		if (isPtInRectangle(rec2[2], rec2[1], rec1))
			return true;

		return false;
	}
};

#endif