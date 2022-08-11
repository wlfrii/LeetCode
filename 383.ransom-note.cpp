#include "myfunctions.h"

/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int idx[26] = {0};
        for(int i = 0; i < magazine.size(); i++){
            idx[magazine[i] - 'a']++;
        }

        for(int i = 0; i < ransomNote.size(); i++){
            idx[ransomNote[i] - 'a']--;
        }

        for(int i = 0; i < 26; i++){
            if(idx[i] < 0){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

