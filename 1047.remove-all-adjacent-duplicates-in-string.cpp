#include "myfunctions.h"

/*
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 */

// @lc code=start
class Solution {
public:
    // #1
    string removeDuplicates(string s) {
        deque<char> charqueue;
        for(int i = 0; i < s.size(); i++){
            if(charqueue.empty()) {
                charqueue.push_back(s[i]);
            }
            else if(s[i] == charqueue.back()) {
                charqueue.pop_back();
            }
            else{
                charqueue.push_back(s[i]);
            }
        }
        string ret;
        ret.resize(charqueue.size());
        for(int i = 0; i< charqueue.size(); i++){
            ret[i] = charqueue[i];
        }
        return ret;
    }

    // #2
    string removeDuplicates2(string s) {
        string ret;
        for(auto ch : s){
            if(!ret.empty() && ch == ret.back()){
                ret.pop_back();
            }
            else{
                ret.push_back(ch);
            }
        }
        return ret;
    }
};

int main()
{
    Solution sln;
    sln.removeDuplicates("abbaca");

    return 0;
}
// @lc code=end

