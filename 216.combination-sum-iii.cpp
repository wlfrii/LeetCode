#include "myfunctions.h"
/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        path.clear();
        results.clear();
        findKSum(n, k, 1);
        return results;
    }

private:
    void findKSum(int n, int k, int start) {
        if(path.size() == k) {
            int sum = 0;
            for(auto & v : path) {
                sum += v;
            }
            if(sum == n) {
                results.push_back(path);
            }
            return;
        }

        for(int i = start; i <= 9; i++) {
            path.push_back(i);
            findKSum(n, k, i+1);
            path.pop_back();
        }
    }

    vector<int> path;
    vector<vector<int>> results;
};
// @lc code=end

