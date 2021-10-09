#include "myFunctions.h"
/**
 * Definition for singly-linked list.
 *
 * struct ListNode
 * {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 * 
 * Thoughts. 2019.8.9
 * 1.Find the real head first.
 */
// Solution One.
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        
        /* determine the head position first */
        while(1)
        {
            if(head->next == nullptr)
                return head;
            if (head->val == head->next->val)
            {
                while (head->val == head->next->val)
                {
                    head = head->next;
                    if(head->next == nullptr)
                        return nullptr;
                }
                head = head->next;
            }
            else
                break; 
        }
        
        /* filter the others
         * because the identical body-nodes will be removed,so we are not first move the node pointer.
         */
        ListNode *it = head;
        while (it->next != nullptr)
        {            
            while (1)
            {
                if(it->next->next == nullptr)
                     return head;
                if (it->next->val == it->next->next->val)
                {
                    while (it->next->val == it->next->next->val)
                    {
                        it->next = it->next->next;
                        if(it->next->next == nullptr)
                        {
                            it->next = nullptr;
                            return head;
                        }
                    }
                    it->next = it->next->next;
                }
                else
                    break;
            } 
            it = it->next;
        }
        return head;
    }
};

int main()
{
    Solution s;
    int n[] = {1,2,3,3,4,4,5,6};
    vector<int> vec(n, n + sizeof(n) / sizeof(int));

    ListNode *lst = createListNode(vec);  
    ListNode *res1 = s.deleteDuplicates(lst);

    int n2[] = {1,1,1,2,2,3,3};
    vector<int> vec2(n2, n2 + sizeof(n2) / sizeof(int));
    lst = createListNode(vec2);
    ListNode *res2 = s.deleteDuplicates(lst);

    lst = nullptr;
    ListNode *res3 = s.deleteDuplicates(lst);   

    int n4[] = {1,2,2,3,3};
    vector<int> vec4(n4, n4 + sizeof(n4) / sizeof(int));
    lst = createListNode(vec4);
    ListNode *res4 = s.deleteDuplicates(lst);
    return 0;
}
