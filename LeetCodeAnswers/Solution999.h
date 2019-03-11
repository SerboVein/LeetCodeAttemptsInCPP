#pragma once
#ifndef SOLUTION_999
#define SOLUTION_999

#include <vector>

using namespace std;
class Solution999 {
public:
	int numRookCaptures(vector<vector<char>>& board) {
		int nCaptures = 0;
		int xRook, yRook;
		bool isfound = false;
		for (xRook = 0; xRook < 8; xRook++)
		{
			for (yRook = 0; yRook < 8; yRook++)
				//board[xRook][yRook] = 3;
				if (board[xRook][yRook] == 'R')
				{
					isfound = true;
					break;
				}
		}
		int x, y;
		for (x = xRook; x >= 0; x--)
		{
			if (board[x][yRook] == 'B')
				break;
			if (board[x][yRook] == 'p')
			{
				nCaptures++;
			}
		}

		for (x = xRook; x < 8; x++)
		{
			if (board[x][yRook] == 'B')
				break;
			if (board[x][yRook] == 'p')
			{
				nCaptures++;
			}
		}

		for (y = yRook; y >= 0; y--)
		{
			if (board[xRook][y] == 'B')
				break;
			if (board[xRook][y] == 'p')
			{
				nCaptures++;
			}
		}

		for (y = yRook; y < 8; y++)
		{
			if (board[xRook][y] == 'B')
				break;
			if (board[xRook][y] == 'p')
			{
				nCaptures++;
			}
		}

		return nCaptures;
	}
}; 
#endif