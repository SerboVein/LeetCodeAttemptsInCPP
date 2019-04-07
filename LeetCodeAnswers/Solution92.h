#pragma once
#ifndef SOLUTION92_H
#define SOLUTION92_H
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
	
};


class Solution92 {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		int i = 1;
		ListNode* current = head;
		ListNode* prevReverse = nullptr;

		while (current)
		{
			if (i == m)
			{

				ListNode* prev = current;
				current = current->next;
				i++;

				while (i <= n && current)
				{
					ListNode* backup = current->next;
					current->next = prev;
					prev = current;
					current = backup;
					i++;
				}

				ListNode* backup = nullptr;
				if (!prevReverse)
				{
					backup = head;
					head = prev;

				}
				else
				{
					backup = prevReverse->next;
					prevReverse->next = prev;
				}
				backup->next = current;
				break;
			}

			i++;
			prevReverse = current;
			current = current->next;
		}

		return head;
	}
};


#endif