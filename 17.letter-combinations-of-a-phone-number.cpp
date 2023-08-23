#include <vector>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    string getLetter(char ch) {
        switch (ch)
        {
        case '2': return "abc";
        case '3': return "def";
        case '4': return "ghi";
        case '5': return "jkl";
        case '6': return "mno";
        case '7': return "pqrs";
        case '8': return "tuv";
        case '9': return "wxyz";
        default:  return "";
        }
    }

    void combine(string digits, int idx, string& path,vector<string>& results) {
        if(path.size() == digits.size()) {
            results.push_back(path);
            return;
        }

        for(int i = idx; i < digits.size(); i++) {
            string letters = getLetter(digits[i]);
            for(int j = 0; j < letters.size(); j++) {
                path.push_back(letters[j]);
                combine(digits, i + 1, path, results);
                path.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> results;
        string path;
        if (!digits.empty()) {
            combine(digits, 0, path, results);
        }
        return results;
    }
};
// @lc code=end

