#include "myfunctions.h"
/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
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
    TreeNode* construtTree(vector<int>& nums, int start, int end){
        if(start == end) return nullptr;
        int max_val = -1;
        int mid = -1;
        for(int i = start; i < end; i++) {
            if(nums[i] > max_val){
                max_val = nums[i];
                mid = i;
            }            
        }
        TreeNode* root = new TreeNode(max_val);
        root->left = construtTree(nums, start, mid);
        root->right = construtTree(nums, mid + 1, end);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construtTree(nums, 0, nums.size());
    }

    // TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    //     int max_val = 0;
    //     int mid = 0;
    //     for(int i = 0; i < nums.size(); i++) {
    //         if(nums[i] > max_val){
    //             max_val = nums[i];
    //             mid = i;
    //         }            
    //     }
    //     TreeNode* root = new TreeNode(max_val);

    //     vector<int> lnums(nums.begin(), nums.begin() + mid);
    //     vector<int> rnums(nums.begin() + mid + 1, nums.end());
    //     root->left = constructMaximumBinaryTree(lnums);
    //     root->right = constructMaximumBinaryTree(rnums);   

    //     return root;
    // }
};

// int main()
// {
//     vector<int> nums = {3,2,1,6,0,5};
//     Solution sln;
//     auto ret = sln.constructMaximumBinaryTree(nums);

//     return 0;
// }
// @lc code=end

