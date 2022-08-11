#include <vector>
using std::vector;

/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:

    // void moveZeroes(vector<int>& nums) {
    //     int i = 0;
    //     while(i < nums.size()){
    //         if(nums[i] == 0) {
    //             bool is_end = true;
    //             int j = i + 1;
    //             while(j < nums.size()) {
    //                 if (nums[j] != 0){
    //                     nums[i] = nums[j];
    //                     nums[j] = 0;
    //                     is_end = false;
    //                     break;       
    //                 }
    //                 j++;
    //             }
    //             if(is_end) break;
    //         }
    //         i++;
    //     }
    // }

    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int k = 1;
        while(j < nums.size()){
            while(nums[i] == 0) {     
                while(j < nums.size()) {
                    if (nums[j] == 0){
                        j++;
                        k++;
                        continue;
                    }
                    break;
                }
                if (j == nums.size()) return;

                nums[i] = nums[j];
                nums[j] = 0;
                j = i+k;
                i++;
            }
            i++;
            j = i+1;
        }
    }
};

int main()
{
    // vector<int> nums = {45192,0,-659,-52359,-99225,-75991,0,-15155,27382,59818,0,-30645,-17025,81209,887,64648};

    vector<int> nums = {0,0,0,0,0,1,2,0,0,0,2,3,0,1};

    Solution s;
    s.moveZeroes(nums);

    return 0;
}
// @lc code=end

