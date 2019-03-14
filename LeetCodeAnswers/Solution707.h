#pragma once
#ifndef SOLUTION707_H
#define SOLUTION707_H

struct LinkNode
{
	int val;
	struct LinkNode* next;
};

class MyLinkedList {
public:
	/** Initialize your data structure here. */
	MyLinkedList() {
		head = nullptr;
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		LinkNode* thisNode = head;
		int i = 0;
		while (thisNode)
		{
			if (i == index)
				return thisNode->val;
			thisNode = thisNode->next;
			i++;
		}

		return -1;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		LinkNode* prevHead = head;
		head = new LinkNode;
		head->val = val;
		head->next = prevHead;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		LinkNode* thisNode = head;

		if (!thisNode)
			addAtHead(val);

		while (thisNode->next)
			thisNode = thisNode->next;

		thisNode->next = new LinkNode;
		thisNode->next->next = nullptr;
		thisNode->next->val = val;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		if (index == 0)
		{
			LinkNode* prevHead = head;
			head = new LinkNode;
			head->val = val;
			head->next = prevHead;
			return;
		}

		LinkNode* thisNode = head;
		int i = 0;

		while (thisNode)
		{
			if (i == index - 1)
				break;

			thisNode = thisNode->next;
			i++;
		}

		if (!thisNode)
			return;

		LinkNode* prevNext = thisNode->next;
		thisNode->next = new LinkNode;
		thisNode->next->val = val;
		thisNode->next->next = prevNext;
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		if (index == 0)
		{
			if (!head)
				return;

			LinkNode* newHead = head->next;
			delete head;
			head = newHead;
			return;
		}

		LinkNode* thisNode = head;
		int i = 0;

		while (thisNode)
		{
			if (i == index - 1)
				break;

			thisNode = thisNode->next;
			i++;
		}

		if (!thisNode || !thisNode->next)
			return;

		LinkNode* nextnext = thisNode->next->next;
		delete thisNode->next;
		thisNode->next = nextnext;
	}

private:
	struct LinkNode *head;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */

#endif