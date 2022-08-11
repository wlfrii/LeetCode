#include "myfunctions.h"

/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        in.push_back(x);
    }
    
    int pop() {
        while(in.size() > 1){
            out.push_back(in.front());
            in.pop_front();
        }
        int res = in.front();
        in.pop_front();
        
        in = out;
        while(!out.empty()){
            out.pop_front();
        }

        return res;
    }
    
    int top() {
        int res = pop();
        in.push_back(res);

        return res;
    }
    
    bool empty() {
        return in.empty();
    }

    deque<int> in;
    deque<int> out;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

