#pragma once
#ifndef SOLUTION86_H
#define SOLUTION86_H

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
	
};

// --------------------------                the following is the memory allocation version   --------------------------

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode* list1 = nullptr, *list2 = nullptr;
		ListNode* current = head, *current1 = nullptr, *current2 = nullptr;
		while (current)
		{
			if (current->val < x)
			{
				if (!current1)
				{
					list1 = new ListNode(current->val);
					current1 = list1;
				}
				else
				{
					current1->next = new ListNode(current->val);
					current1 = current1->next;
				}

			}
			else
			{
				if (!current2)
				{
					list2 = new ListNode(current->val);
					current2 = list2;
				}
				else
				{
					current2->next = new ListNode(current->val);
					current2 = current2->next;
				}

			}
			current = current->next;
		}

		if (current1)
		{
			current1->next = list2;
			return list1;
		}
		else
			return list2;
	}
};

//------------------------------------------------ direct list reorder method (no new memory allocation) --------------------------------------------------

class Solution86 {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode* list1 = nullptr, *list2 = nullptr;
		ListNode* current = head, *current1 = nullptr, *current2 = nullptr;
		while (current)
		{
			if (current->val < x)
			{
				if (!current1)
				{
					list1 = current;
					current1 = list1;
				}
				else
				{
					current1->next = current;
					current1 = current;
				}

			}
			else
			{
				if (!current2)
				{
					list2 = current;
					current2 = list2;
				}
				else
				{
					current2->next = current;
					current2 = current;
				}

			}
			current = current->next;
		}

		current2->next = nullptr;
		if (current1)
		{
			current1->next = list2;
			return list1;
		}
		else
			return list2;
	}
};

#endif