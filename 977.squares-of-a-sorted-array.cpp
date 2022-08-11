#include <vector>
using std::vector;

/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
class Solution {
public:
    // vector<int> sortedSquares(vector<int>& nums) {
    //     if (nums.empty()) return nums;

    //     vector<int> ret;
        
    //     if(nums[0] >= 0){
    //         for(auto& num : nums){
    //             ret.emplace_back(num*num);
    //         }
    //     }
    //     else{
    //         int i = 0;
    //         while(i < nums.size()){
    //             if(nums[i] >= 0) break;
    //             i++;    
    //         }
    //         int j = i - 1;
    //         while (j >= 0 && i < nums.size()){
    //             if(abs(nums[j]) >= nums[i]){
    //                 ret.emplace_back(nums[i]*nums[i]);
    //                 i++;
    //             }
    //             else{
    //                 ret.emplace_back(nums[j]*nums[j]);
    //                 j--;
    //             }
    //         }
    //         if(j < 0){
    //             while (i < nums.size()){
    //                 ret.emplace_back(nums[i]*nums[i]);
    //                 i++;
    //             }
    //         }
    //         if(i >= nums.size()){
    //             while (j >= 0){
    //                 ret.emplace_back(nums[j]*nums[j]);
    //                 j--;
    //             }
    //         }
    //     }

    //     return ret;
    // }

    // #2
    vector<int> sortedSquares(vector<int>& nums) {
        int k = nums.size();
        vector<int> ret(k);

        int i = 0, j = nums.size() - 1;
        while(i <= j){
            int i_start = nums[i]*nums[i];
            int i_end = nums[j]*nums[j];
            if( i_start > i_end ){
                ret[--k] = i_start;
                i++;
            }
            else{
                ret[--k] = i_end;
                j--;
            }
        }

        return ret;
    }
};
// @lc code=end

