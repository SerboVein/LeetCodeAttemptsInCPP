#include <iostream>
#include <vector>

using namespace std;

struct POINT
{
	int x;
	int y;
};

bool visitedCutRightUpLeftDown[40][50];
bool visitedCutLeftUpRightDown[40][50];
bool visitedCutLeftRight[50];
bool visitedCutTopDown[40];
vector<POINT> vFruits;
int fruitsMap[40][50];

void clearVisited()
{
	for (int x = 0; x < 40; x++)
		for (int y = 0; y < 50; y++)
		{
			visitedCutRightUpLeftDown[x][y] = false;
			visitedCutLeftUpRightDown[x][y] = false;
			visitedCutLeftRight[y] = false;
			visitedCutTopDown[x] = false;
		}
}

int getThisFruitCut(int iFruit, int &cutType)
{
	//x from 0 to 39
	//y from 0 to 49    

	// up down cut ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	int MaxFruitsOneCut = 0;
	int nfruitsThisCut = 0;
	if (!visitedCutLeftRight[vFruits[iFruit].y])
	{
		visitedCutLeftRight[vFruits[iFruit].y] = true;
		for (int x = 0; x < 40; x++)
			if (fruitsMap[x][vFruits[iFruit].y])
				nfruitsThisCut++;
		if (nfruitsThisCut > MaxFruitsOneCut)
		{
			cutType = 1;
			MaxFruitsOneCut = nfruitsThisCut;
		}
	}


	// left right cut ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	nfruitsThisCut = 0;
	if (!visitedCutTopDown[vFruits[iFruit].x])
	{
		visitedCutTopDown[vFruits[iFruit].x] = true;
		for (int y = 0; y < 50; y++)
			if (fruitsMap[vFruits[iFruit].x][y])
				nfruitsThisCut++;
		if (nfruitsThisCut > MaxFruitsOneCut)
		{
			cutType = 2;
			MaxFruitsOneCut = nfruitsThisCut;
		}
	}

	// top_left ----> right_down cut ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


	nfruitsThisCut = 0;
	int leftStX = 0, leftStY = 0;

	if (vFruits[iFruit].x > vFruits[iFruit].y)
	{
		leftStX = vFruits[iFruit].x - vFruits[iFruit].y;
		leftStY = 0;
	}
	else
	{
		leftStY = vFruits[iFruit].y - vFruits[iFruit].x;
		leftStX = 0;
	}

	if (!visitedCutLeftUpRightDown[leftStX][leftStY])
	{
		visitedCutLeftUpRightDown[leftStX][leftStY] = true;
		for (int inc = 0; leftStX + inc < 40 && leftStY + inc < 50; inc++)
			if (fruitsMap[leftStX + inc][leftStY + inc])
				nfruitsThisCut++;
		if (nfruitsThisCut > MaxFruitsOneCut)
		{
			cutType = 3;
			MaxFruitsOneCut = nfruitsThisCut;
		}
	}


	// left-down -------> up-right cut ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	nfruitsThisCut = 0;
	leftStX = 0, leftStY = 0;

	if (vFruits[iFruit].x > 49 - vFruits[iFruit].y)
	{
		leftStX = vFruits[iFruit].x - (49 - vFruits[iFruit].y);
		leftStY = 49;
	}
	else
	{
		leftStY = vFruits[iFruit].y + vFruits[iFruit].x;
		leftStX = 0;
	}

	if (!visitedCutRightUpLeftDown[leftStX][leftStY])
	{
		visitedCutRightUpLeftDown[leftStX][leftStY] = true;
		for (int inc = 0; leftStX + inc < 40 && leftStY - inc >= 0; inc++)
			if (fruitsMap[leftStX + inc][leftStY - inc])
				nfruitsThisCut++;
		if (nfruitsThisCut > MaxFruitsOneCut)
		{
			cutType = 3;
			MaxFruitsOneCut = nfruitsThisCut;
		}
	}

	return MaxFruitsOneCut;
}

int CutFruitsByType(int iAnchorFruit, int cutType)
{
	int AnchorX = vFruits[iAnchorFruit].x;
	int AnchorY = vFruits[iAnchorFruit].y;
	int ActualCut = 0;
	if (cutType == 1)
	{
		for (int x = 0; x < 40; x++)
			if (fruitsMap[x][AnchorY])
			{
				vFruits[fruitsMap[x][AnchorY]].x = -1;
				fruitsMap[x][AnchorY] = 0;
				ActualCut++;
			}
	}
	else if (cutType == 2)
	{
		for (int y = 0; y < 50; y++)
			if (fruitsMap[AnchorX][y])
			{
				vFruits[fruitsMap[AnchorX][y]].x = -1;
				fruitsMap[AnchorX][y] = 0;
				ActualCut++;
			}
	}
	else if (cutType == 3)
	{
		int leftStX = 0, leftStY = 0;

		if (AnchorX > AnchorY)
		{
			leftStX = AnchorX - AnchorY;
			leftStY = 0;
		}
		else
		{
			leftStY = AnchorY - AnchorX;
			leftStX = 0;
		}

		for (int inc = 0; leftStX + inc < 40 && leftStY + inc < 50; inc++)
			if (fruitsMap[leftStX + inc][leftStY + inc])
			{
				vFruits[fruitsMap[leftStX + inc][leftStY + inc]].x = -1;
				fruitsMap[leftStX + inc][leftStY + inc] = 0;
				ActualCut++;
			}

	}
	else
	{
		int leftStX = 0, leftStY = 0;

		if (AnchorX > 49 - AnchorY)
		{
			leftStX = AnchorX - (49 - AnchorY);
			leftStY = 49;
		}
		else
		{
			leftStY = AnchorX + AnchorY;
			leftStX = 0;
		}

		for (int inc = 0; leftStX + inc < 40 && leftStY - inc >= 0; inc++)
			if (fruitsMap[leftStX + inc][leftStY - inc])
			{
				vFruits[fruitsMap[leftStX + inc][leftStY - inc]].x = -1;
				fruitsMap[leftStX + inc][leftStY - inc] = 0;
				ActualCut++;
			}
	}
	return ActualCut;
}

int main()
{
	for (int x = 0; x < 40; x++)
		for (int y = 0; y < 50; y++)
			fruitsMap[x][y] = 0;

	vFruits.push_back({ -1,-1 }); //serve as padding to avoid 0 if test failure
	int nFruits = 0;
	cin >> nFruits;
	for (int iFruit = 0; iFruit < nFruits; iFruit++)
	{
		int x, y;
		cin >> x >> y;
		fruitsMap[x][y] = iFruit;
		vFruits.push_back({ x,y });
	}
	// use greedy here, every time try to cut the most possible
	int nCuts = 0;
	while (nFruits != 0)
	{
		int MaxFruitsOneCut = 0;
		int iMaxCutFruit = -1;
		int typeMaxCut = -1;
		clearVisited();
		//find the cut of most fruits
		for (int iFruit = 0; iFruit < vFruits.size(); iFruit++)
		{
			if (vFruits[iFruit].x == -1)
				continue;
			int thisCutType = 0;
			int thisMaxCut = getThisFruitCut(iFruit, thisCutType);
			if (thisMaxCut > MaxFruitsOneCut)
			{
				MaxFruitsOneCut = thisMaxCut;
				iMaxCutFruit = iFruit;
				typeMaxCut = thisCutType;
			}
		}
		int ActualCut = 0;
		if (MaxFruitsOneCut < nFruits)
			ActualCut = CutFruitsByType(iMaxCutFruit, typeMaxCut);
		else
			ActualCut = nFruits;

		nFruits -= ActualCut;
		nCuts++;
		//if(nCuts > 4)
		//    return 0;
	}

	cout << nCuts;
	//cout << endl;
	return 0;
}