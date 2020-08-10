#include "myFunctions.h"
/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * Idea.
 * We need two head-nodes at least to represent two parts between the target value x.
 * First step:
 *   Front part. Just store the values which are less than x.
 *   Rear part. Just store the values which are greater than or equal to value x.
 * Second step:
 *   Make the first value of rear part as the last node of first part, and followed by x, then followed by the revised rear part, which has been made the second nodes as its head.
 * Notes:
 *   It is possible that first part or sencond part is empty.
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr) 
            return nullptr;
        else if(head->next == nullptr)
            return head;
        // filter
        ListNode *head1, *tail1, *head2, *tail2;
        head1 = nullptr;
        head2 = nullptr;
        while(head != nullptr)
        {
            if(head->val < x)
            {
                if(head1 == nullptr)
                    head1 = tail1 = new ListNode(head->val);
                else
                {
                    ListNode* add = new ListNode(head->val);
                    tail1->next = add;
                    tail1 = add;
                }
            }
            else
            {
                if(head2 == nullptr)
                    head2 = tail2 = new ListNode(head->val);
                else
                {
                    ListNode* add = new ListNode(head->val);
                    tail2->next = add;
                    tail2 = add;
                }
            }
            head = head->next;
        }

        // combine
        if(head1 == nullptr)
        {
            return head2;
        }
        else if(head2 == nullptr)
        {
            return head1;
        }
        else
        {
            tail1->next = head2;
            return head1;
        }    
    }
};
int main()
{
    Solution s;

    int a[] = {1,4,3,2,5,2};
    vector<int> v(a, a + sizeof(a) / sizeof(int));
    ListNode *head = createListNode(v);
    
    ListNode *res1 = s.partition(head, 3);


    return 0;
}

