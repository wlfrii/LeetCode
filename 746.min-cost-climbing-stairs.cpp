#include "myfunctions.h"
/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        size_t n = cost.size();
        vector<int> dp(cost.size());
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(size_t i = 2; i < cost.size(); i++) {
            dp[i] = std::min(dp[i-1], dp[i-2]) + cost[i];
        }
        return std::min(dp[n-2], dp[n-1]);
    }
};
// @lc code=end

