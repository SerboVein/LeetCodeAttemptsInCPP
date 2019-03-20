#pragma once
#ifndef SOLUTION19_H
#define SOLUTION19_H

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
对于目前的这个问题，我应该如何去思考？

删除倒数第n个节点
目前，我需要界定极端情况的范围。

link list的大小为n。

只有当linklist只有一个元素的时候，才会返回null，否则返回的总是有意义的。
总是返回head.

分两种情况： 1.head不变，2.head发生变化。

head发生变化只有一种情况：
	所删除的节点正是头节点。

数组长度为k，while循环只会执行k-1次。
当  i >= n  时，beforeTarget开始变化。
i代表了循环执行的次数。
只有当循环已经执行i次以后，beforeTarget才开始变化。
循环需要执行n+1次，beforeTarget变化。
k-1 >= n + 1
k >= n + 2

若beforeTarget没有变化，则 k < n + 2，此时应该进行特殊的处理。


k > = n + 2意味着： 前2个元素，无法通过该方法删除。

只要beforeTarget指向正确的元素即可

 */


class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {

		ListNode* beforeTarget = head;
		ListNode* end = head;
		int i = 0;

		while (end->next)
		{
			end = end->next;
			if (i >= n)
				beforeTarget = beforeTarget->next;
			i++;
		}

		if (i + 1 == n)
		{
			ListNode* temp = head->next;
			delete head;
			return temp;
		}

		ListNode* temp = beforeTarget->next->next;
		delete beforeTarget->next;
		beforeTarget->next = temp;

		return head;
	}
};

#endif