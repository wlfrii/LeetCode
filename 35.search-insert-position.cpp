#include <vector>
using std::vector;

/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
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
            else {
                return id;
            }
        }

        return i_start;
    }
};
// @lc code=end

