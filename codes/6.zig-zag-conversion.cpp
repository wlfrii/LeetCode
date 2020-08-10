#include <string>
using std::string;
/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 */
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 0)
            return "";
        if(s.size() <= 1 || numRows == 1)
            return s;

        string res("");
        int a_period = 2 * numRows - 2;
        int row = 0;
        while(row < numRows)
        {
            int start = row;
            while(start < s.size())
            {
                res += s[start];
                start += a_period;
                if(row != 0 && row != numRows - 1 && start - 2*row < s.size())
                    res += s[start - 2*row];
            }
            row++;
        }
        return res;
    }
};

int main()
{
    string str = "PAYPALISHIRING";

    Solution s;

    string res1 = s.convert(str,3);
    string res2 = s.convert(str,4);
    string res3 = s.convert(str,5);

    return 0;
}

