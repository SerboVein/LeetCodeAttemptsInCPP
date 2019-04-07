#pragma once
#ifndef SOLUTION142_H
#define SOLUTION142_H

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};


class Solution142 {
public:
	ListNode *getPrev(ListNode* head, ListNode* current)
	{
		if (head == current)
			return nullptr;

		while (head)
		{
			if (head->next == current)
				return head;

			head = head->next;
		}

		return nullptr;
	}

	ListNode *detectCycle(ListNode *head) {
		ListNode *backupHead = head;
		ListNode *check = nullptr;
		ListNode *prevCheck = nullptr;
		int cycleGuess = 2;
		int cycleCount = 0;

		while (head)
		{
			if (check == head)
			{
				bool isPrevChecked = false;
				do
				{
					isPrevChecked = false;
					prevCheck = getPrev(backupHead, check);
					if (!prevCheck)
						break;

					for (int i = 0; i < cycleGuess; i++)
					{
						if (head == prevCheck)
						{
							check = prevCheck;
							isPrevChecked = true;
							break;
						}
						head = head->next;
					}

				} while (isPrevChecked);

				return check;
			}

			cycleCount++;
			if (cycleCount == cycleGuess)
			{
				check = head;
				cycleGuess *= 2;
				cycleCount = 0;
			}

			head = head->next;
		}

		return nullptr;
	}
};


#endif