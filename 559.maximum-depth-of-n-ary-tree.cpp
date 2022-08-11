#include "myfunctions.h"

/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] Maximum Depth of N-ary Tree
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
    // #1
    // int maxDepth(Node* root) {
    //     if(!root) return 0;
    //     int depth = 0;
    //     for(auto child : root->children){
    //         depth = std::max(depth, maxDepth(child));
    //     }
    //     return depth + 1;
    // }

    // #2 Via levelOrder
    int maxDepth(Node* root) {
        queue<Node*> que;
        if(root) que.push(root);
        int depth = 0;
        while(!que.empty()) {
            int size = que.size();
            for(int i = 0; i < size; i++) {
                Node* node = que.front();
                que.pop();
                for(auto child : node->children){
                    if(child) que.push(child);
                }
            }
            depth++;
        }
        return depth;
    }
};
// @lc code=end

