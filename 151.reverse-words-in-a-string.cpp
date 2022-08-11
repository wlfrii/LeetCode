#include "myfunctions.h"
/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution {
public:
    // string reverseWords(string s) {
    //     string ret = "";
    //     int pos = 0;
    //     while(pos < s.size()){
    //         while(s[pos] == ' '){
    //             pos++;
    //         }
    //         if(pos >= s.size()) break;

    //         int tmp = pos;
    //         while(s[tmp] != ' ' && tmp < s.size()){
    //             tmp++;
    //         }
    //         ret = " " + s.substr(pos, tmp - pos) + ret;
            
    //         pos = tmp;
    //     }
    //     return ret.substr(1);
    // }

    void reverseStr(string& s, int start, int end){
        for(int i = start, j = end; i < j; i++, j--){
            swap(s[i], s[j]);
        }
    }

    void removeExtraSpace(string& s){
        int slow = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ' '){
                if(slow != 0) s[slow++] = ' ';
                while(i < s.size() && s[i] != ' '){
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow);
    }

    string reverseWords(string s) {
        reverseStr(s, 0, s.size() - 1);
        removeExtraSpace(s);
        int start = 0;
        for(int i = 0; i <= s.size(); i++){
            if(i == s.size() || s[i] == ' '){
                reverseStr(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }
};

int main()
{
    Solution s;
    string ret = s.reverseWords("the sky is blue");

    ret = s.reverseWords("  hello world  ");

    ret = s.reverseWords("a good  example");

    return 0;
}
// @lc code=end

