#include "myfunctions.h"
/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
class Solution {
public:
    // int strStr(string haystack, string needle) {
    //     if(needle.empty()) return 0;

    //     for(int i = 0; i <= haystack.size() - needle.size(); i++){
    //         if(needle == haystack.substr(i, needle.size())){
    //             return i;
    //         }
    //     }
    //     return -1;
    // }

    void getNext(int* next, const string& s){
        int j = 0;
        next[0] = j;
        for(int i = 1; i < s.size(); i++){
            while(j > 0 && s[j] != s[i]){
                j = next[j - 1];
            }
            if(s[j] == s[i]){
                j++;
            }
            next[i] = j;
        }
    }

    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        
        int next[needle.size()];
        getNext(next, needle);
        
        int j = 0;
        for(int i = 0; i < haystack.size(); i++){
            while(j > 0 && haystack[i] != needle[j]){
                j = next[j - 1];
            }
            if(haystack[i] == needle[j]){
                j++;
            }
            if(j == needle.size()){
                return (i - j + 1);
            }
        }

        return -1;
    }
};

int main()
{
    Solution sln;
    // int res = sln.strStr("aabaabaaf", "aabaaf");
    int res = sln.strStr("hello", "ll");

    return 0;
}
// @lc code=end

