#include <string>
using std::string;
/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int i = 2; i <= s.size() / 2; i++){
            string str = s.substr(0, i);
            for(int j = i; j < s.size(); j++){
                string jstr = s.substr(j, i);
                if(str == jstr) return true;
            }
        }
        
        return false;
    }
};

int main()
{
    Solution s;
    s.repeatedSubstringPattern("abab");

    return 0;
}
// @lc code=end

