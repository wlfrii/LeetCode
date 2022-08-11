#include "myfunctions.h"

/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        int idx[1005] = {0};
        for(auto num : nums1) {
            idx[num]++;
        }
        for(auto num : nums2) {
            if(idx[num] != 0){
                ret.push_back(num);
                idx[num]--;
            }
        }
        return ret;
    }
};
// @lc code=end

