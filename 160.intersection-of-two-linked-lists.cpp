#include "myfunctions.h"

/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode* tmpA = headA;
        ListNode* tmpB = headB;
        while(tmpA){
            lenA++;
            tmpA = tmpA->next;
        }
        while(tmpB){
            lenB++;
            tmpB = tmpB->next;
        }

        tmpA = headA;
        tmpB = headB;
        if(lenA < lenB){
            swap(tmpA, tmpB);
            swap(lenA, lenB);
        }
        int gap = lenA - lenB;
        while(gap--){
            tmpA = tmpA->next;
        }

        while(tmpA){
            if (tmpA == tmpB){
                return tmpA;
            }
            tmpA = tmpA->next;
            tmpB = tmpB->next;
        }

        return nullptr;
    }
};
// @lc code=end

