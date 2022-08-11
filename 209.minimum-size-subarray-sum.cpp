#include <vector>
using std::vector;

/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_len = nums.size() + 1;
        int j = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            while(sum >= target){
                if(min_len > (i - j + 1)){
                    min_len = i - j + 1;
                }
                sum -= nums[j++];
            }
        }
        
        return min_len == nums.size() + 1 ? 0 : min_len;
    }
};
// @lc code=end

