#include "myfunctions.h"
/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
/* Idea 1:
 *  Comparing the head value first, then insert ListNode
 *  with greater head value into another ListNode, 
 *  we assume the l1 always has a smaller head value 
 * Idea 2:
 *  Comparing each value in l1 and l2, then connect the two
 *  ListNode.
 */ 
class Solution {
public:
    // Version 1: 8 ms (77.41%) + 14.4 MB (71.45)
    /*ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr)
            return nullptr;
        if(l1 == nullptr)    return l2;
        if(l2 == nullptr)    return l1;

        // assume l1 always has a smaller head value
        if(l1->val > l2->val){
            ListNode* tmp = l1;
            l1 = l2;
            l2 = tmp;
        }

        ListNode* node1 = l1;
        ListNode* node2 = l1->next;
        while(l2 != nullptr)
        {
            if(node2 == nullptr) {
                node1->next = l2;
                break;
            }

            if(l2->val <= node2->val) {
                node1->next = l2;
                l2 = l2->next;
                node1 = node1->next;
                node1->next = node2;
            }
            else{
                node1 = node2;
                node2 = node1->next;
            }
        }
        return l1;
    }*/

    // Version 2: refers to others
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr)    return l2;
        if(l2 == nullptr)    return l1;

        if(l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

int main()
{
    enum{ NUM = 4 };
    ListNode* lst_node1[NUM] = {
        lf::createListNode({1,2,4}),
        lf::createListNode({1}),
        lf::createListNode({1,3,5,7}),
        lf::createListNode({4,11,17,18})
    };
    ListNode* lst_node2[NUM] = {
        lf::createListNode({1,3,4}),
        lf::createListNode({1,3,4}),
        lf::createListNode({3,3,8}),
        lf::createListNode({2,4,7,8})
    };

    ListNode* res[NUM];
    Solution sln;
    for(int i = 0; i < int(NUM); i++)
    {
        res[i] = sln.mergeTwoLists(lst_node1[i], lst_node2[i]);
    }

    return 0;
}
// @lc code=end

