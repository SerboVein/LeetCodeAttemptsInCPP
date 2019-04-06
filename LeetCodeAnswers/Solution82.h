#pragma once
#ifndef SOLUTION82_H
#define SOLUTION82_H

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
 
class Solution82 {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* current = head;
		
		ListNode* prev = nullptr;
		ListNode* target = nullptr;
		while (current && current->next)
		{
			if (current->next->val == current->val)
			{
				target = current->next->next;
				delete current->next;
				while (target && target->val == current->val)
				{
					ListNode* backup = target->next;
					delete target;
					target = backup;
				}
				delete current;

				if (!prev)
					head = target;
				else
					prev->next = target;

				current = target;
				continue;
			}
		
			prev = current;
			current = current->next;
		}

		return head;
	}
};



#endif