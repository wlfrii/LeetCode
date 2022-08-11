#include <vector>
#include <deque>
using std::vector;
using std::deque;
/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        deque<int> tmp;
        int n = -1;
        while(++n < k && n < nums.size() ){
            while(!tmp.empty() && nums[n] > tmp.back()){
                tmp.pop_back();
            }
            tmp.push_back(nums[n]);
        }
        ret.push_back(tmp.front());

        for(n = k; n < nums.size(); n++){
            if(tmp.front() == nums[n - k]){
                tmp.pop_front();
            }

            while(!tmp.empty() && nums[n] > tmp.back()){
                tmp.pop_back();
            }
            tmp.push_back(nums[n]);
            ret.push_back(tmp.front());
        }

        return ret;
    }
};

int main()
{
    Solution sln;
    // vector<int> nums = {1,3,-1,-3,5,3,6,7};
    // auto ret = sln.maxSlidingWindow(nums, 3);
    vector<int> nums = {1,3,1,2,0,5};
    auto ret = sln.maxSlidingWindow(nums, 3);


    return 0;
}
// @lc code=end

