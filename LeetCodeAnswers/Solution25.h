#pragma once
#ifndef SOLUTION25_H
#define SOLUTION25_H

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution25 {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		int GroupCnt = 0;
		ListNode* prevGroup = nullptr;
		ListNode* stGroup = head;
		ListNode* current = head;

		while (current)
		{
			GroupCnt++;

			if (GroupCnt == k)
			{
				//start reversing the current group 

				ListNode* nextGroup = current->next;
				ListNode* prev = stGroup;
				ListNode* cReverse = stGroup->next;


				while (cReverse != nextGroup)
				{
					ListNode* backup = cReverse->next;
					cReverse->next = prev;
					prev = cReverse;
					cReverse = backup;
				}

				if (!prevGroup)
					head = current;
				else
					prevGroup->next = current;

				stGroup->next = nextGroup;
				prevGroup = stGroup;
				stGroup = nextGroup;
				current = nextGroup;
				GroupCnt = 0;
				continue;
			}

			current = current->next;
		}

		return head;
	}
};

#endif