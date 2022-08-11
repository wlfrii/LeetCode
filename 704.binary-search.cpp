#include <vector>
using std::vector;

/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i_start = 0;
        int i_end = nums.size() - 1;
        while(i_start <= i_end) {
            int id = (i_end + i_start) / 2.f;
            if(nums[id] < target) {
                i_start = id + 1;
            }
            else if (nums[id] > target) {
                i_end = id - 1;
            }
            else {
                return id;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    std::vector<int> nums = { -1, 0, 3, 5, 9, 12};
    int out = s.search(nums, 9);
    
    out = s.search(nums, 2);

    return 0;
}
// @lc code=end

