#include <string>
using std::string;

/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        int index[26] = {0};
        for(int i = 0; i < s.size(); i++){
            index[s[i] - 'a']++;
        }
        for(int i = 0; i < t.size(); i++){
            index[t[i] - 'a']--;
        }

        for(int i = 0; i < 26; i++){
            if(index[i] != 0){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

