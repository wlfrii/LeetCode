#include "myfunctions.h"

/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;

        ListNode* left = dummyhead->next;
        ListNode* right = left;
        while(n--){
            if(!right){
                return head;
            }
            right = right->next;
        }

        ListNode* left_prev = dummyhead;
        while(right != nullptr){
            left_prev = left;
            left = left->next;
            right = right->next;
        }
        left_prev->next = left->next;
        delete left;

        return dummyhead->next;
    }
};

int main()
{
    ListNode* head = lf::createListNode({1});
    Solution s;
    s.removeNthFromEnd(head, 1);

    return 0;
}

// @lc code=end

