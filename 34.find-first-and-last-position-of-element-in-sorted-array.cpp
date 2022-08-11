#include <vector>
using std::vector;

/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1,-1};

        int i_start = 0;
        int i_end = nums.size() - 1;
        while(i_start <= i_end){
            int id = (i_start + i_end) / 2;
            if(nums[id] > target){
                i_end = id - 1;
            }
            else if(nums[id] < target){
                i_start = id + 1;
            }
            else{
                i_start = id;
                while(i_start-1 >= 0 && nums[i_start-1] == nums[id]) {
                    i_start--;
                }
                i_end = id;
                while(i_end+1 < nums.size() && nums[i_end+1] == nums[id]) {
                    i_end++;
                }
                
                return {i_start, i_end};
            }
        }
        return {-1, -1};
    }
};
// @lc code=end

