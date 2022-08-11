#include "myfunctions.h"

/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    // ListNode* reverseList(ListNode* head) {
    //     if(!head) return head;

    //     ListNode* next = head->next;
    //     ListNode* tmp = head;
    //     tmp->next = nullptr;

    //     while(next != nullptr && next->next != nullptr){
    //         ListNode *curr = next;
    //         next = next->next;

    //         curr->next = tmp;
    //         tmp = curr;
    //     }
    //     if(next != nullptr){
    //         next->next = tmp;
    //         tmp = next;
    //     }

    //     return tmp;
    // }

    ListNode* reverseList(ListNode* head) {
        ListNode* tmp;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr){
            tmp = curr->next;
            curr->next = prev;

            prev = curr;
            curr = tmp;
        }
        return prev;
    }
};

int main()
{
    ListNode* head = lf::createListNode({1,2,3,4,5});
    Solution s;
    ListNode* node = s.reverseList(head);

    return 0;
}

// @lc code=end

