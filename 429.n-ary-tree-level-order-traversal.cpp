#include "myfunctions.h"
/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> que;
        if(root) que.push(root);

        vector<vector<int>> result;
        while(!que.empty()){
            int size = que.size();
            vector<int> res;
            for(int i = 0; i < size; i++) {
                Node* node = que.front();
                que.pop();
                res.push_back(node->val);
                for(auto child : node->children){
                    if(child) que.push(child);
                }
            }
            result.push_back(res);
        }   
        return result;
    }
};
// @lc code=end

