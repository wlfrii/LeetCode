#include "myfunctions.h"
/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        // a + b + c + d = target
        for(int a = 0; a < nums.size(); a++){
            if(nums[a] > target && target >= 0) {
                break;
            }
            if(a > 0 && nums[a] == nums[a - 1]) continue;

            for(int b = a + 1; b < nums.size(); b++){
                if(nums[a] + nums[b] > target && target >= 0) {
                    break;
                }
                if(b > a + 1 && nums[b] == nums[b - 1]) continue;

                int c = b + 1;
                int d = nums.size() - 1;
                while(c < d){
                    long sum = nums[a] + nums[b] + nums[c] + nums[d];
                    if(sum > target) d--;
                    else if(sum < target) c++;
                    else{
                        ret.push_back({nums[a], nums[b], nums[c], nums[d]});

                        while(c < d && nums[c] == nums[c + 1]) c++;
                        while(c < d && nums[d] == nums[d - 1]) d--;
                        
                        c++;
                        d--;
                    }
                }
            }
        }
        return ret;
    }
};

int main()
{
    // vector<int> nums = {2, 2, 2, 2, 2};
    // Solution s;
    // auto ret = s.fourSum(nums, 8);
    // vector<int> nums = {1, -2, -5, -4, -3, 3, 3, 5};
    // Solution s;
    // auto ret = s.fourSum(nums, -11);
    vector<int> nums = {0, 0, 0, 10000, 10000, 10000, 10000};
    Solution s;
    auto ret = s.fourSum(nums, 10000);

    return 0;
}


// @lc code=end

