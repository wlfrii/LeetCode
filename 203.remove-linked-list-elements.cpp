#include "myfunctions.h"

/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    ListNode* removeElements(ListNode* head, int val) {
        while(head != nullptr && head->val == val){
            ListNode *tmp = head;
            head = head->next;
            delete tmp;
        }
        ListNode *tail = head;

        while(tail != nullptr && tail->next != nullptr){
            if(tail->next->val == val){
                ListNode *next = tail->next;
                tail->next = tail->next->next;
                delete next;
            }else{
                tail = tail->next;   
            }
        }

        return head;
    }
};

int main()
{
    vector<int> nums = {1,2,6,3,4,5,6};
    ListNode* nodes = lf::createListNode(nums);
    Solution s;
    ListNode* ret = s.removeElements(nodes, 6);

    return  0;
}

// @lc code=end

