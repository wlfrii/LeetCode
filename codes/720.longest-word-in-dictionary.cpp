#include "myFunctions.h"
/*
 * @lc app=leetcode id=720 lang=cpp
 *
 * [720] Longest Word in Dictionary
 */
class Solution {
public:
    string longestWord(vector<string>& words) {
        if(words.size() < 1 || words.size() > 1000)
            return "";
        if(words.size() == 1)
            return words[0];
        
        string res = words[0];
        unsigned char num1 = 0;
        num1 = charNumOfString(words[0], num1);

        unsigned char num = 0;
        for(auto it = words.begin() + 1; it != words.end(); ++it)
        {
            num = charNumOfString(*it, num);
            if(num1 < num)
            {
                num1 = num;
                res = *it;
            }
            else if(num1 == num)
            {
                res = compareString(res, *it);
            }
        }
        return res;
    }
private:
    unsigned char & charNumOfString(const string &s, unsigned char &num) const{
        num = 0;
        for(unsigned int i = 0; i < s.size(); ++i)
        {
            if(s.find(s[i]) == i)
                num++;
        }
        return num;
    }

    string & compareString(string &s1, string &s2)
    {
        for(int i = 0; i < s1.size(); ++i)
        {
            if(s1[i] < s2[i])
                return s1;
            else if(s1[i] > s2[i])
                return s2;
        }
        return s1;
    }
};

int main()
{
    string s1[5] = {"w","wo","wor","worl", "world"};
    vector<string> vs1(s1, s1 + 5);

    string s2[7] = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    vector<string> vs2(s2, s2 + 7);

    string s3[13] = {"m", "mo", "moc", "moch", "mocha", "l", "la", "lat", "latt", "latte", "c", "ca", "cat"};
    vector<string> vs3(s3, s3 + 13);

    vector<string> test = lf::createVectorString(2, "h", "w");

    string res1, res2, res3, res4;
    Solution sln;
    res1 = sln.longestWord(vs1);
    res2 = sln.longestWord(vs2);
    res3 = sln.longestWord(vs3);


    return 0;
}
