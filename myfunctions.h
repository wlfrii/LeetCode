#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

#include <algorithm>
#include <string>
#include <vector>
#include <stdarg.h>   /* va_list, va_start, va_arg, va_end */
#include <chrono>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>


using namespace std;
using chrono::duration;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/****************************************************************
 *                    Introduction
 * 1. @ createListNode()
 * 
 * 2. @ createVector()
 * 
 * 
 * ***********************************************************/
namespace lf
{

ListNode* createListNode(const vector<int> &vec)
{
    if(vec.size() < 1)
        return nullptr;
    ListNode *head = new ListNode(vec[0]);
    ListNode *tail = head;

    for(auto it = vec.cbegin() + 1; it != vec.cend(); ++it)
    {
        ListNode *add = new ListNode(*it);
        tail->next = add;
        tail = add;
    }
    return head;
}

vector<int> createVectorInt(unsigned int numbers,...)
{
    vector<int> res;
    va_list vlst;
    va_start(vlst, numbers);
    for(unsigned int i = 0; i < numbers; i++)
    {
        int val = va_arg(vlst, int);
        res.push_back(val);
    }
    va_end(vlst);
    return res;
}

vector<string> createVectorString(unsigned int numbers,...)
{
    vector<string> res;
    va_list vlst;
    va_start(vlst, numbers);
    for(unsigned int i = 0; i < numbers; i++)
    {
        const char* cval;
        cval = va_arg(vlst, const char*);
        res.push_back(cval);
    }
    va_end(vlst);
    return res;
}

/* ************************************************************* */
#define Timer(...) 	{ \
                    auto start = system_clock::now(); \
                    __VA_ARGS__; \
                    auto end = system_clock::now(); \
                    auto duration = duration_cast<microseconds>(end - start); \
                    cout << "Time consuming is: "<< double(duration.count()) * microseconds::period::num / microseconds::period::den<< "ms" << endl; \
					} \

} // end namespace lf

#endif