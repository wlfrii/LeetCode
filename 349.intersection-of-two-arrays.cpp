#include "myfunctions.h"

/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> res_set;
        unordered_set<int> nums1_set(nums1.begin(), nums1.end());
        for(auto num : nums2){
            if(nums1_set.find(num) != nums1_set.end()) {
                res_set.insert(num);
            }
        }
        return vector<int>(res_set.begin(), res_set.end());
    }
};
// @lc code=end

