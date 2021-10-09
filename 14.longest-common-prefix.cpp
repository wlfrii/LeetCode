#include "myFunctions.h"
/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        else if(strs.size() == 1)
            return strs[0];
        
        string res = "";
        int idx = 0;
        while(true)
        {
            for (auto it = strs.cbegin() + 1; it != strs.cend(); it++)
            {
                if (strs[0][idx] != (*it)[idx] || idx >= strs[0].size() || idx >= it->size())
                    return res;
            }
            idx++;
            res = strs[0].substr(0, idx);
        }
    }
};

int main()
{
    Solution sln;

    string res1,res2,res3,res4;
    vector<string> str1,str2,str3,str4;
    str1.push_back("flower");str1.push_back("flow");str1.push_back("flight");
    str2.push_back("dog");str2.push_back("racecar");str2.push_back("car");

    res1 = sln.longestCommonPrefix(str1);
    res2 = sln.longestCommonPrefix(str2);

    return 0;
}

