/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        if(root) que.push(root);

        while(!que.empty()){
            int size = que.size();
            Node* prev = nullptr;
            for(int i = 0; i < size; i++) {
                Node* node = que.front();
                que.pop();
                if(prev) prev->next = node;
                prev = node;

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            prev->next = nullptr;
        }
        return root;
    }
};
// @lc code=end

