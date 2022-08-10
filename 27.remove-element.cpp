#include "myfunctions.h"
/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i_begin = 0;
        int i_end = nums.size() - 1;
        while(i_begin <= i_end){
            if(nums[i_begin] == val){
                nums[i_begin] = nums[i_end];
                i_end--;
            }
            else{
                i_begin++;
            }
        }
        return i_begin;
    }
};

// int main()
// {

//     return 0;
// }

// @lc code=end

