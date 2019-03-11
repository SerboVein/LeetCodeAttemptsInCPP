#pragma once
#ifndef SOLUTION206_H
#define SOLUTION206_H

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
 
class Solution206 {
public:
	ListNode* reverseThis(ListNode* thisNode, ListNode* prev)
	{
		if (!thisNode)
			return nullptr;

		ListNode* next = thisNode->next;
		thisNode->next = prev;

		if (thisNode->next != nullptr)
			return reverseThis(thisNode->next, thisNode);
		else
			return thisNode;
	}

	ListNode* reverseList(ListNode* head) {
		return reverseThis(head, nullptr);
	}
};


#endif