// LeetCodeAnswers.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "Solution166.h" //166. Fraction to Recurring Decimal
#include "Solution5.h" //longest sub palindrome
#include "Solution214.h" //shortest palindrome
#include "Solution459.h"
#include "Solution999.h"
#include "Solution409.h"
#include "Solution13.h"


int main()
{
	Solution5  solution5;
	Solution166 solution166;
	Solution214 solution214;
	Solution459 solution459;
	Solution999 solution999;
	Solution409 solution409;
	Solution13 solution13;

	std::cout << "result:" << solution13.romanToInt("MCMXCIV");
	return 0;

	std::cout << "result:" << solution409.longestPalindrome("abccccdd") << std::endl;
//	std::cout << "result:  " << solution999.numRookCaptures(chessBoard) << std::endl;
    std::cout << "Hello World!\n"; 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
