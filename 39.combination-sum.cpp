#include "myfunctions.h"
/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> results;
    vector<int> path;

    void backtrack(vector<int>& candidates, int target, int sum, int idx) {
        if(sum == target) {
            results.push_back(path);
            return;
        }
        else if(sum > target) {
            return;
        }

        for(size_t i = idx; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtrack(candidates, target, sum, i);
            path.pop_back();
            sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        results.clear();
        path.clear();
        if(!candidates.empty()) {
            backtrack(candidates, target, 0, 0);
        }
        return results;
    }
};
// @lc code=end

