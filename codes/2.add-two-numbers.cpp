#include <cmath>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x)
		: val(x)
		, next(nullptr)
	{}
};
/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        unsigned int val = l1->val + l2->val;
	unsigned int up = floor(val / 10);

	ListNode *head = new ListNode(val % 10);
	ListNode *tail = head;
	while (l1->next != nullptr || l2->next != nullptr || up != 0)
	{
		if (l1->next == nullptr)
			l1->next = new ListNode(0);
		if (l2->next == nullptr)
			l2->next = new ListNode(0);

		l1 = l1->next;
		l2 = l2->next;
		val = l1->val + l2->val + up;
		up = floor(val / 10);

		ListNode *add = new ListNode(val % 10);
		tail->next = add;
		tail = add;
	}
	return head;
    }
};

// int main()
// {
//     ListNode* l1 = new ListNode(1);
// 	l1->next = new ListNode(0);
// 	l1->next->next = new ListNode(0);
// 	l1->next->next->next = new ListNode(0);
// 	l1->next->next->next->next = new ListNode(0);
// 	l1->next->next->next->next->next = new ListNode(0);
// 	l1->next->next->next->next->next->next = new ListNode(0);
// 	l1->next->next->next->next->next->next->next = new ListNode(0);
// 	l1->next->next->next->next->next->next->next->next = new ListNode(0);
// 	l1->next->next->next->next->next->next->next->next->next = new ListNode(0);
// 	l1->next->next->next->next->next->next->next->next->next->next = new ListNode(1);

// 	ListNode* l2 = new ListNode(5);
// 	l2->next = new ListNode(6);
// 	l2->next->next = new ListNode(4);

//     Solution s;
// 	ListNode *res = s.addTwoNumbers(l1, l2);

//     return 0;
// }
