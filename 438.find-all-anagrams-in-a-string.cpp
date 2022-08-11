#include "myfunctions.h"

/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        if(p.size() > s.size()) return ret;

        int idx[26] = {0};
        for(int i = 0; i < p.size(); i++){
            idx[p[i] - 'a']++;
        } 
        int count = 0;
        for(int i = 0; i < 26; i++){
            if(idx[i] != 0) count++;
        }

        auto isanagram = [&idx](string& str) -> bool{
            int id[26] = {0};
            for(int i = 0; i < str.size(); i++){
                id[str[i] - 'a']++;
            }
            for(int i = 0; i < 26; i++){
                if(id[i] != idx[i]) return false;
            }
            return true;
        };

        for(int i = 0; i <= s.size() - count; i++){
            string str = s.substr(i, count);
            if(isanagram(str)) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};
// @lc code=end

