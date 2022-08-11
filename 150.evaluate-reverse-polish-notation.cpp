#include "myfunctions.h"
/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> res;
        for(int i = 0; i < tokens.size(); i++){
            auto& str = tokens[i];
            if(str == "+" || str == "-" || str == "*" || str == "/") {
                int v2 = res.top();     res.pop();
                int v1 = res.top();     res.pop();
                if(tokens[i] == "+")      v1 = v1 + v2;
                else if(tokens[i] == "-") v1 = v1 - v2;
                else if(tokens[i] == "*") v1 = v1 * v2;
                else if(tokens[i] == "/") v1 = v1 / v2;
                res.push(v1);
            }
            else{
                res.push(stoi(tokens[i]));
            }
        }
        return res.top();
    }
};
// @lc code=end

