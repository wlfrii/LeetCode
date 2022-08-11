#include "myfunctions.h"

/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyhead = new ListNode();
        dummyhead->next = head;
        ListNode* curr = dummyhead;
        while(curr->next != nullptr && curr->next->next != nullptr){
            ListNode* tmp = curr->next->next->next;
            ListNode* n1 = curr->next;
            curr->next = curr->next->next;
            curr->next->next = n1;
            n1->next = tmp;

            curr = curr->next->next;
        }

        return dummyhead->next;
    }
};
// @lc code=end

