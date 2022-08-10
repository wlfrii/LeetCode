#include "myfunctions.h"
/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 * 
 * Corresponding relation table.
 *   binary     decimal   hex   character
 *  0010 1011     43      2B       +
 *  0010 1101     45      2D       -
 *  0011 0000     48      30       0
 *  0011 0001     49      31       1
 *  0011 0010     50      32       2
 *  0011 0011     51      33       3
 *  0011 0100     52      34       4
 *  0011 0101     53      35       5
 *  0011 0110     54      36       6
 *  0011 0111     55      37       7
 *  0011 1000     56      38       8
 *  0011 1001     57      39       9
 */
class Solution {
public:
    // /* Method 1 */
    // int myAtoi(string str) {
    //     if(str.size() < 1)
    //         return 0;
        
    //     while(str[0] == ' ')
    //         str.erase(0, 1);
        
    //     bool isPositive;
    //     if(str[0] == 43) 
    //     {
    //         isPositive = true;
    //         str.erase(0, 1);
    //     }    
    //     else if(str[0] == 45) 
    //     {
    //          isPositive = false;
    //          str.erase(0, 1);
    //     }
    //     else if (str[0] >= 48 && str[0] <= 59)
    //         isPositive = true;
    //     else
    //         return 0;
        
    //     if(str[0] < 48 || str[0] > 59)
    //         return 0;
        
    //     long res = 0;
    //     int count = 0;
    //     while(str[count] >= 48 && str[count] <= 59 && count < str.size()) 
    //     {
    //         res = res*10 + (int)(str[count]) - 48;
    //         if(isPositive && res >= pow(2, 31) - 1)
    //             return pow(2, 31) - 1;
    //         else if(!isPositive && -res <= -pow(2, 31))
    //             return -pow(2, 31);

    //         count++;
    //     }
    //     return isPositive ? (int)res : -(int)res;
    // }

    /* Method 2, revising the erase() */
    int myAtoi(string str) {
        if(str.size() < 1)
            return 0;
        
        int start = 0;
        while(str[start] == ' ')
            start++;
        
        bool isPositive = true;
        if(str[start] == 43) 
            start++;  
        else if(str[start] == 45) 
        {
             isPositive = false;
             start++;
        }
        
        if(str[start] < 48 || str[start] > 59)
            return 0;
        
        long long res = 0;
        while(str[start] >= 48 && str[start] <= 59 && start < str.size()) 
        {
            res = res*10 + (int)(str[start]) - 48;
            if(isPositive && res >= pow(2, 31) - 1)
                return pow(2, 31) - 1;
            else if(!isPositive && -res <= -pow(2, 31))
                return -pow(2, 31);

            start++;
        }
        return isPositive ? (int)res : -(int)res;
    }
};

int main()
{
    string str1 = "42";
    string str2 = "      -42";
    string str3 = "4193 with words";
    string str4 = "words and 987";
    string str5 = "-91283472332";
    string str6 = "-2147483648";

    Solution s;
    int res1 = s.myAtoi(str1);
    int res2 = s.myAtoi(str2);
    int res3 = s.myAtoi(str3);
    int res4 = s.myAtoi(str4);
    int res5 = s.myAtoi(str5);
    int res6 = s.myAtoi(str6);
    
    return 0;
}
