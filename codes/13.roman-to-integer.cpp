#include "myFunctions.h"
/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */
class Solution {
public:// Method 1 --- 20 ms	8.4 MB 
    // int romanToInt(string s) {
    //     if(s.size() == 0)
    //         return 0;
    //     int idx(0), res(0);
    //     while(idx < s.size())
    //     {
    //         switch (s[idx])
    //         {
    //         case 'M':
    //             res += 1000;
    //             break;
    //         case 'D':
    //             res += 500;
    //             break;
    //         case 'C':
    //             if(idx + 1 < s.size() && s[idx+1] == 'M')
    //             {
    //                 res += 900;
    //                 idx++;
    //             }
    //             else if(idx + 1 < s.size() && s[idx+1] == 'D')
    //             {
    //                 res += 400;
    //                 idx++;
    //             }
    //             else
    //                 res += 100;
    //             break;
    //         case 'L':
    //             res += 50;
    //             break;
    //         case 'X':
    //             if(idx + 1 < s.size() && s[idx+1] == 'C')
    //             {
    //                 res += 90;
    //                 idx++;
    //             }
    //             else if(idx + 1 < s.size() && s[idx+1] == 'L')
    //             {
    //                 res += 40;
    //                 idx++;
    //             }
    //             else
    //                 res += 10;
    //             break;
    //         case 'V':
    //             res += 5;
    //             break;
    //         case 'I':
    //             if(idx + 1 < s.size() && s[idx+1] == 'X')
    //             {
    //                 res += 9;
    //                 idx++;
    //             }
    //             else if(idx + 1 < s.size() && s[idx+1] == 'V')
    //             {
    //                 res += 4;
    //                 idx++;
    //             }
    //             else
    //                 res += 1;
    //             break;
    //         default:
    //             break;
    //         }
    //         idx++;
    //     }
    //     return res;
    // }
public:// Method 2 --- 12 ms	8.4 MB  /  4 ms	8.4 MB
    // int romanToInt(string s) {
    //     if(s.size() == 0)
    //         return 0;
    //     int idx(0), res(0);
    //     while(s[idx] == 'M' && idx < s.size())
    //     {
    //         res += 1000;
    //         idx++;
    //     }
    //     while(s[idx] == 'D' && idx < s.size())
    //     {
    //         res += 500;
    //         idx++;
    //     }
    //     while(s[idx] == 'C' && idx < s.size())
    //     {
    //         if(idx + 1 < s.size() && s[idx+1] == 'M')
    //         {
    //             res += 900;
    //             idx++;  // idx += 2; continue;
    //         }
    //         else if (idx + 1 < s.size() && s[idx + 1] == 'D')
    //         {
    //             res += 400;
    //             idx++;  // idx += 2; continue;
    //         }
    //         else
    //             res += 100;
    //         idx++;
    //     }
    //     while(s[idx] == 'L' && idx < s.size())
    //     {
    //         res += 50;
    //         idx++;
    //     }
    //     while(s[idx] == 'X' && idx < s.size())
    //     {
    //         if (idx + 1 < s.size() && s[idx + 1] == 'C')
    //         {
    //             res += 90;
    //             idx++;  // idx += 2; continue;
    //         }
    //         else if (idx + 1 < s.size() && s[idx + 1] == 'L')
    //         {
    //             res += 40;
    //             idx++;  // idx += 2; continue;
    //         }
    //         else
    //             res += 10;
    //         idx++;
    //     }
    //     while(s[idx] == 'V' && idx < s.size())
    //     {
    //         res += 5;
    //         idx++;
    //     }
    //     while(s[idx] == 'I' && idx < s.size())
    //     {
    //         if(idx + 1 < s.size() && s[idx+1] == 'X')
    //         {
    //             res += 9;
    //             idx++;  // idx += 2; continue;
    //         }
    //         else if (idx + 1 < s.size() && s[idx + 1] == 'V')
    //         {
    //             res += 4;
    //             idx++;  // idx += 2; continue;
    //         }
    //         else
    //             res += 1;
    //         idx++;
    //     }
    //     return res;
    // }
public:// Method 3 --- 12 ms	8.5 MB
    int romanToInt(string s) {
        if (s.size() == 0)
            return 0;
        int res(0);
        while(s[0] == 'M' && s.size() > 0)
        {
            res += 1000;
            s = s.substr(1, s.size() - 1);
        }
        while(s[0] == 'D' && s.size() > 0)
        {
            res += 500;
            s = s.substr(1, s.size() - 1);
        }
        while(s[0] == 'C' && s.size() > 0)
        {
            if(s.size() > 1 && s[1] == 'M')
            {
                res += 900;
                s = s.substr(2, s.size() - 1);
                continue;
            }
            else if (s.size() > 1 && s[1] == 'D')
            {
                res += 400;
                s = s.substr(2, s.size() - 1);
                continue;
            }
            else
                res += 100;
            s = s.substr(1, s.size() - 1);
        }
        while(s[0] == 'L' && s.size() > 0)
        {
            res += 50;
            s = s.substr(1, s.size() - 1);
        }
        while(s[0] == 'X' && s.size() > 0)
        {
            if (s.size() > 1 && s[1] == 'C')
            {
                res += 90;
                s = s.substr(2, s.size() - 1);
                continue;
            }
            else if (s.size() > 1 && s[1] == 'L')
            {
                res += 40;
                s = s.substr(2, s.size() - 1);
                continue;
            }
            else
                res += 10;
            s = s.substr(1, s.size() - 1);
        }
        while(s[0] == 'V' && s.size() > 0)
        {
            res += 5;
            s = s.substr(1, s.size() - 1);
        }
        while(s[0] == 'I' && s.size() > 0)
        {
            if(s.size() > 1 && s[1] == 'X')
            {
                res += 9;
                s = s.substr(2, s.size() - 1);
                continue;
            }
            else if (s.size() > 1 && s[1] == 'V')
            {
                res += 4;
                s = s.substr(2, s.size() - 1);
                continue;
            }
            else
                res += 1;
            s = s.substr(1, s.size() - 1);
        }
        return res;
    }
};

int main()
{
    int res1,res2,res3,res4,res5,res6;

    Solution sln;

    res1 = sln.romanToInt("III");
    res2 = sln.romanToInt("IV");
    res3 = sln.romanToInt("IX");
    res4 = sln.romanToInt("LVIII");
    res5 = sln.romanToInt("MCMXCIV");

    return 0;
}

