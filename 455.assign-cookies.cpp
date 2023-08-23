#include <vector>
using std::vector;

/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int count = 0;
        int j = s.size() - 1;
        for(int i = g.size() - 1; i >= 0; i--) {
            if(j >= 0 && s[j] >= g[i]) {
                count++;
                j--;
            }
        }
        return count;
    }
};
// @lc code=end

