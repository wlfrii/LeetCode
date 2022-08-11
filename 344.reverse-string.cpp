#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        size_t n = s.size();
        for(size_t i = 0; i < n / 2; i++) {
            int left = s[i];
            int right = s[n - 1 - i];
            s[i] = right;
            s[n - 1 - i] = left;
        }
    }
};
// @lc code=end

