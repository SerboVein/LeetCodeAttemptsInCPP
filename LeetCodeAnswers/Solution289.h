#pragma once
#ifndef SOLUTION289_H
#define SOLUTION289_H

#include <vector>
using namespace std;

class Solution289 {
public:
	int getLiveNeighborCounts(vector<vector<int>>& board, int x, int y)
	{
		int nLives = 0;
		for (int i = -1; i <= 1; i++)
			for (int j = -1; j <= 1; j++)
				if (x + i >= 0 && x + i < board.size() && y + i >= 0 && y + i < board[x].size())
					if (((board[x + i][y + j] % 10) != 0) && (i != 0 || j != 0))
						nLives++;

		return nLives;
	}

	void gameOfLife(vector<vector<int>>& board) {
		for (int x = 0; x < board.size(); x++)
			for (int y = 0; y < board[x].size(); y++)
			{

				int nLiveNeighbors = getLiveNeighborCounts(board, x, y);
				board[x][y] += nLiveNeighbors * 10;
				continue;
				if (board[x][y] % 10)
				{
					if (nLiveNeighbors < 2)
						board[x][y] += 10;
					else if (nLiveNeighbors > 3)
						board[x][y] += 10;   // 10 : becomes dead 
				}
				else if (nLiveNeighbors == 3)
					board[x][y] += 20;  // 20 : becomes alive 

			}

		for (int x = 0; x < board.size(); x++)
			for (int y = 0; y < board[x].size(); y++)
			{
				board[x][y] /= 10;
				continue;

				int change = board[x][y] / 10;
				if (change == 1)
					board[x][y] = 0;   //becomes dead
				else if (change == 2)
					board[x][y] = 1;   //becomes alive
			}
	}
};
#endif