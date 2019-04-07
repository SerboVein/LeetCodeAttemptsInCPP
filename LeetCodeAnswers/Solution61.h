#pragma once
#ifndef SOLUTION61_H
#define SOLUTION61_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
 };

//-------------------------------------------------------this code requires optimizing !!!!!!!!!!!!! --------------------------------------------

class Solution61 {
public:
	ListNode* tryRotateRight(ListNode* head, int k, int &len)
	{
		int iStart = 0;
		ListNode* current = head;
		ListNode* newhead = head;
		ListNode* prevNewhead = nullptr;
		bool isInLength;

		if (k == 0)
			return head;

		while (current->next)
		{
			if (iStart >= k - 1)
			{
				prevNewhead = newhead;
				newhead = newhead->next;
			}
			iStart++;
			current = current->next;
		}

		if (iStart < k)
		{
			len = iStart;
			return nullptr;
		}

		current->next = head;
		prevNewhead->next = nullptr;

		return newhead;

	}

	ListNode* rotateRight(ListNode* head, int k) {
		if (!head)
			return nullptr;
		if (k == 0 || !head->next)
			return head;

		int len = 0;
		ListNode* result = tryRotateRight(head, k, len);

		if (!result)
		{
			int lenBackup = len;
			int accumulate = 0;
			result = head;
			result = tryRotateRight(result, k % (len + 1), len);
		}

		return result;
	}
};

#endif