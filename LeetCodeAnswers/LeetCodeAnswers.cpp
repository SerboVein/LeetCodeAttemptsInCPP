// LeetCodeAnswers.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
//#include "Solution166.h" //166. Fraction to Recurring Decimal
//#include "Solution5.h" //longest sub palindrome
//#include "Solution214.h" //shortest palindrome
//#include "Solution459.h"
//#include "Solution999.h"
//#include "Solution409.h"
//#include "Solution13.h"
//#include "Solution206.h"
//#include "Solution804.h"
//#include "Solution977.h"
//#include "Solution295.h"
//#include "Solution930.h"
//#include "Solution219.h"
//#include "Solution67.h"
//#include "Solution66.h"
//#include "Solution508.h"
//#include "Solution111.h"
#include "Solution572.h"


int main()
{/*
	Solution5  solution5;
	Solution166 solution166;
	Solution214 solution214;
	Solution459 solution459;
	Solution999 solution999;
	Solution409 solution409;
	Solution13 solution13;
	Solution206 solution206;*/
	//Solution804 solution804;
	//Solution977 solution977;
	//Solution930 solution930;
	//Solution219 solution219;
	////Solution67 solution67;
	//Solution66 solution66;
	//Solution508 solution508;
	//Solution111 solution111;
	Solution572 solution572;
	//MedianFinder mf;

	//mf.addNum(5);
	//mf.addNum(10);
	//mf.addNum(15);
	//mf.addNum(2);
	//vector<int> nums = { 1,2,3,1,2,3 };
	//vector<int> digits = {9};
	//TreeNode root(3);
	//TreeNode node1(9);
	//TreeNode node2(20);
	//TreeNode node3(15);
	//TreeNode node4(7);
	//root.left = &node1;
	//root.right = &node2;
	//node2.left = &node3;
	//node2.right = &node4;
	TreeNode root1(3);
	TreeNode node1(4);
	TreeNode node2(1);
	TreeNode node3(2);
	TreeNode node4(5);
	root1.left = &node1;
	root1.right = &node4;
	node1.left = &node2;
	node1.right = &node3;

	TreeNode root2(4);
	TreeNode node5(1);
	TreeNode node6(2);
	root2.left = &node5;
	root2.right = &node6;

	std::cout << "result:" << solution572.isSubtree(&root1, &root2);
	//solution66.plusOne(digits);
	//std::cout << "result:" << solution66.plusOne(digits) << std::endl;

	/*std::cout << "result:" << solution67.addBinary("11", "1") << std::endl;

	std::cout << "result:" << solution219.containsNearbyDuplicate(nums, 2) << std::endl;

	std::cout << "median finder :" << mf.findMedian() << std::endl;
	*///vector<int> problem = {-4, -1, 0, 3, 10};
	//auto result = solution977.sortedSquares(problem);
	//ListNode one(1);
	//ListNode two(2);
	//ListNode three(3);
	//ListNode four(4);
	//ListNode five(5);
	//one.next = &two; two.next = &three; three.next = &four; four.next = &five;
	//ListNode* result = solution206.reverseList(&one);
	//vector<string> problem = { "gin", "zen", "gig", "msg" };
	//std::cout << solution804.uniqueMorseRepresentations(problem);
	//std::cout << "result:" << solution13.romanToInt("MCMXCIV");
	//return 0;

	//std::cout << "result:" << solution409.longestPalindrome("abccccdd") << std::endl;
	//std::cout << "result:  " << solution999.numRookCaptures(chessBoard) << std::endl;
 //   std::cout << "Hello World!\n"; 
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
