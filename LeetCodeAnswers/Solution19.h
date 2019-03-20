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
����Ŀǰ��������⣬��Ӧ�����ȥ˼����

ɾ��������n���ڵ�
Ŀǰ������Ҫ�綨��������ķ�Χ��

link list�Ĵ�СΪn��

ֻ�е�linklistֻ��һ��Ԫ�ص�ʱ�򣬲Ż᷵��null�����򷵻ص�����������ġ�
���Ƿ���head.

����������� 1.head���䣬2.head�����仯��

head�����仯ֻ��һ�������
	��ɾ���Ľڵ�����ͷ�ڵ㡣

���鳤��Ϊk��whileѭ��ֻ��ִ��k-1�Ρ�
��  i >= n  ʱ��beforeTarget��ʼ�仯��
i������ѭ��ִ�еĴ�����
ֻ�е�ѭ���Ѿ�ִ��i���Ժ�beforeTarget�ſ�ʼ�仯��
ѭ����Ҫִ��n+1�Σ�beforeTarget�仯��
k-1 >= n + 1
k >= n + 2

��beforeTargetû�б仯���� k < n + 2����ʱӦ�ý�������Ĵ���


k > = n + 2��ζ�ţ� ǰ2��Ԫ�أ��޷�ͨ���÷���ɾ����

ֻҪbeforeTargetָ����ȷ��Ԫ�ؼ���

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