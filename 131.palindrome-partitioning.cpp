#include "myfunctions.h"
/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> results;
    vector<string> path;

    bool isPalindrome(const string& s, int start, int end) {
        for(int i = start, j = end; i < j; i++, j--) {
            if(s[i] != s[j])  return false;
        }
        return true;
    }

    void backtrack(string s, int idx) {
        if(idx >= s.size()) {
            results.push_back(path);
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            if (isPalindrome(s, idx, i)) {   
                string str = s.substr(idx, i - idx + 1);
                path.push_back(str);
            } else {                                
                continue;
            }
            backtrack(s, i + 1);
            path.pop_back(); 
        }
    }

    vector<vector<string>> partition(string s) {
        results.clear();
        path.clear();
        if(!s.empty()) {
            backtrack(s, 0);
        }
        return results;
    }
};

// int main()
// {
//     string s = "aab";

//     Solution sln;
//     auto res = sln.partition(s);

//     return 0;
// }
// @lc code=end

