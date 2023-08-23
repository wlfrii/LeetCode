#include "myfunctions.h"
/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traverse_inorder(TreeNode* node, unordered_map<int, int>& map){
        if(!node) return;
        traverse_inorder(node->left, map);
        map[node->val]++;
        traverse_inorder(node->right, map);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        if(root) {
            unordered_map<int, int> map;
            traverse_inorder(root, map);
            vector<pair<int, int>> freq(map.begin(), map.end());

            auto cmp = [](const pair<int, int>& lh, const pair<int, int>& rh) -> bool {
                return lh.second > rh.second;
            };
            sort(freq.begin(), freq.end(), cmp);

            result.push_back(freq[0].first);
            for(int i = 1; i < freq.size(); i++) {
                if(freq[i].second == freq[0].second) {
                    result.push_back(freq[i].first);
                }
            }
        }
        return result;
    }
};
// @lc code=end

