#include "myfunctions.h"

/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 */

// @lc code=start
class MyLinkedList {
public:
    MyLinkedList() 
        : head(nullptr)
    { 
    }

    ~MyLinkedList()
    {
        while(head != nullptr){
            ListNode *tmp = head;
            head = head->next;
            delete tmp;
            tmp = nullptr;
        }
    }
    
    int get(int index) {
        ListNode *tmp = head;
        while(tmp != nullptr){
            if(index-- == 0){
                return tmp->val;
            }
            tmp = tmp->next;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        ListNode *add = new ListNode(val);
        if(head){
            add->next = head;
        }
        head = add;
    }
    
    void addAtTail(int val) {
        if(!head){
            head = new ListNode(val);
        }
        else{
            ListNode *tmp = head;
            while(tmp->next != nullptr){
                tmp = tmp->next;
            }
            tmp->next = new ListNode(val);
        }
    }
    
    void addAtIndex(int index, int val) {
        if(index == 0) {
            addAtHead(val);
            return;
        }

        ListNode *tmp = head;
        while(tmp != nullptr && tmp->next != nullptr){
            if(--index == 0){
                ListNode *add = new ListNode(val);
                ListNode *next = tmp->next;
                tmp->next = add;
                add->next = next;
                return;
            }
            tmp = tmp->next;
        }
        if(tmp != nullptr && --index == 0){
            tmp->next = new ListNode(val);
        }
    }
    
    void deleteAtIndex(int index) {
        if(index == 0) {
            ListNode *tmp = head;
            head = head->next;
            delete tmp;
            tmp = nullptr;   
            return; 
        }

        ListNode *tmp = head->next;
        ListNode *prev = head;
        while(tmp != nullptr){
            if(--index == 0){
                prev->next = tmp->next;
                delete tmp;
                tmp = nullptr; 
                return;
            }
            prev = tmp;
            tmp = tmp->next;
        }   
    }

private:
    ListNode *head;
};


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main()
{
    MyLinkedList myLinkedList;

    // ["MyLinkedList","addAtHead","addAtHead","addAtHead","addAtIndex","deleteAtIndex","addAtHead","addAtTail","get","addAtHead","addAtIndex","addAtHead"]
    // [[],[7],[2],[1],[3,0],[2],[6],[4],[4],[4],[5,0],[6]]
    // Output: [null,null,null,null,null,null,null,null,4,null,null,null]
    // myLinkedList.addAtHead(7);
    // myLinkedList.addAtHead(2);
    // myLinkedList.addAtHead(1);
    // myLinkedList.addAtIndex(3, 0);    
    // myLinkedList.deleteAtIndex(2);
    // myLinkedList.addAtHead(6);
    // myLinkedList.addAtTail(4);
    // int val = myLinkedList.get(4);
    // myLinkedList.addAtHead(4);
    // myLinkedList.addAtIndex(5, 0);    
    // myLinkedList.addAtHead(6);

    // myLinkedList.addAtIndex(1, 0);
    // myLinkedList.get(0);
    
    myLinkedList.addAtHead(1);
    myLinkedList.addAtTail(3);
    myLinkedList.addAtIndex(1, 2);
    int ret = myLinkedList.get(1); 
    myLinkedList.deleteAtIndex(1);
    ret = myLinkedList.get(1);

    return 0;
}

// @lc code=end

