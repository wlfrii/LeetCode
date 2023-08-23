#include "myfunctions.h"
/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
public:
    void findKSet(int start, int n, int k, vector<int> &path, vector<vector<int>>& results) {
        if(path.size() == k) {
            results.push_back(path);
            return;
        }

        for(int i = start; i <= n; i++) {
            path.push_back(i);
            findKSet(i+1, n, k, path, results);
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        vector<vector<int>> results;
        findKSet(1, n, k, path, results);
        return results;
    }
};
// @lc code=end

