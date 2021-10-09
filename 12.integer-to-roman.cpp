#include "myFunctions.h"
/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 * 
 * Symbol       Value
 *  I             1
 *  V             5
 *  X             10
 *  L             50
 *  C             100
 *  D             500
 *  M             1000
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * 
 *   4 ms	8.4 MB
 * {
        typedef unsigned char u8;
        u8 num_M = num / 1000;
        u8 num_C = (num % 1000) / 100;
        u8 num_X = (num % 1000 % 100) / 10;
        u8 num_I = num % 1000 % 100 % 10;

        string M("M"), D("D"), C("C"), L("L"), X("X"), V("V"), I("I");

        string res = "";
        for(u8 i = 0; i < num_M; i++)
            res += "M";
        
        res = addRoman(res, num_C, M, D, C);
		res = addRoman(res, num_X, C, L, X);
		res = addRoman(res, num_I, X, V, I);
 *  }
 * 
 *   current version: 4 ms	8.3 MB
 */
class Solution {
public:
    string intToRoman(int num) {
        if(num < 1 || num > 3999)
            return "";
        
        string res = "";
        // numbers of M
        unsigned char n = num / 1000;
        for(unsigned char i = 0; i < n; i++)
            res += "M";

        //string M("M"), D("D"), C("C"), L("L"), X("X"), V("V"), I("I");
        string high, middle, low;

        // numbers of C
        n = (num % 1000) / 100;
        high = "M"; middle = "D"; low = "C";
        res = addRoman(res, n, high, middle, low);
        // numbers of X
        n = (num % 1000 % 100) / 10;
        high = "C"; middle = "L"; low = "X";
		res = addRoman(res, n, high, middle, low);
        // numbers of I
        n = num % 1000 % 100 % 10;
        high = "X"; middle = "V"; low = "I";
		res = addRoman(res, n, high, middle, low);

        return res;
    }
private:
    string& addRoman(string& romanStr, unsigned char &num, string &high, string &middle, string &low)
    {
        if(num == 9)
            romanStr += low + high;
        else if(num >= 5)
        {
            romanStr += middle;
            for(unsigned char i = 0; i < num - 5; i++)
                romanStr += low;
        }
        else if(num == 4)
            romanStr += low + middle;
        else
            for(unsigned char i = 0; i < num; i++)
                romanStr += low;
        
        return romanStr;
    }
};

int main()
{
    Solution sln;

    string res1,res2,res3,res4,res5,res6,res7;
    res1 = sln.intToRoman(3);
    res2 = sln.intToRoman(4);
    res3 = sln.intToRoman(9);
    res4 = sln.intToRoman(58);
    res5 = sln.intToRoman(1994);
    res6 = sln.intToRoman(787);
    res7 = sln.intToRoman(3749);

    return 0;
}
