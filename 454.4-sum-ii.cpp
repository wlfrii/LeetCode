#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> res;
        for(auto val1 : nums1){
            for(auto val2 : nums2){
                res[val1 + val2]++;
            }
        }
        int count = 0;
        for(auto val3 : nums3){
            for(auto val4 : nums4){
                auto ret = res.find(-val3 - val4);
                if(ret != res.end()){
                    count += ret->second;
                }
            }
        }
        return count;
    }
};
// @lc code=end

