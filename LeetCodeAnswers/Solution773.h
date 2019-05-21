#pragma once
#ifndef SOLUTION773_H
#define SOLUTION773_H

#include <vector>
#include <queue>
using namespace std;

class Solution773 {
public:
	struct State {
		vector<vector<int>> board;
		int prevMove;
		int moveCnt;
		int zeroX;
		int zeroY;
	};

	bool checkBoardValid(vector<vector<int>>& board)
	{
		if (board[0][0] != 1 ||
			board[0][1] != 2 ||
			board[0][2] != 3 ||
			board[1][0] != 4 ||
			board[1][1] != 5)
			return false;

		return true;
	}

	//move type : 0(up), 1(down), 2(left), 3(right)


	int slidingPuzzle(vector<vector<int>>& board) {
		int x, y;
		int zeroX, zeroY;
		for (x = 0; x < board.size(); x++)
			for (y = 0; y < board[0].size(); y++)
				if (board[x][y] == 0)
				{
					zeroX = x;
					zeroY = y;
					break;
				}

		queue<State> bfsQueue;
		bfsQueue.push({ board,-1,0,zeroX,zeroY });
		while (bfsQueue.size())
		{
			struct State current = bfsQueue.front();
			bfsQueue.pop();
			if (current.zeroX == 1 && current.zeroY == 2)
				if (checkBoardValid(current.board))
					return current.moveCnt;

			//up 
			if (current.zeroY > 0 && current.prevMove != 1)
			{
				vector<vector<int>> newBoard(current.board);
				int backup = newBoard[current.zeroX][current.zeroY - 1];
				newBoard[current.zeroX][current.zeroY - 1] = newBoard[current.zeroX][current.zeroY];
				newBoard[current.zeroX][current.zeroY] = backup;
				bfsQueue.push({ newBoard,0, current.moveCnt + 1,current.zeroX,current.zeroY - 1 });
			}

			//down 
			if (current.zeroY < 2 && current.prevMove != 0)
			{
				vector<vector<int>> newBoard(current.board);
				int backup = newBoard[current.zeroX][current.zeroY + 1];
				newBoard[current.zeroX][current.zeroY + 1] = newBoard[current.zeroX][current.zeroY];
				newBoard[current.zeroX][current.zeroY] = backup;
				bfsQueue.push({ newBoard,1, current.moveCnt + 1,current.zeroX,current.zeroY + 1 });
			}

			//left 
			if (current.zeroX > 0 && current.prevMove != 3)
			{
				vector<vector<int>> newBoard(current.board);
				int backup = newBoard[current.zeroX - 1][current.zeroY];
				newBoard[current.zeroX - 1][current.zeroY] = newBoard[current.zeroX][current.zeroY];
				newBoard[current.zeroX][current.zeroY] = backup;
				bfsQueue.push({ newBoard,2, current.moveCnt + 1,current.zeroX - 1,current.zeroY });
			}

			//right 
			if (current.zeroX < 1 && current.prevMove != 2)
			{
				vector<vector<int>> newBoard(current.board);
				int backup = newBoard[current.zeroX + 1][current.zeroY];
				newBoard[current.zeroX + 1][current.zeroY] = newBoard[current.zeroX][current.zeroY];
				newBoard[current.zeroX][current.zeroY] = backup;
				bfsQueue.push({ newBoard,3, current.moveCnt + 1,current.zeroX + 1,current.zeroY });
			}

		}

		return -1;
	}
};

#endif