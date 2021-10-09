#include <cmath>
/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */
class Solution {
public:
    int reverse(int x) {
        // exclude e.g. 1200000
        while(x != 0 && x % 10 == 0)
            x = x / 10;
        // exclude single numbers
        if(abs(x) < 10)
            return x;
        // reverse
        long long res = 0;
        while(x != 0)
        {
            int rem = x % 10;
            res = res * 10 + rem;
            x = floor(x / 10);

            if(res > (pow(2, 31) - 1) || res < -pow(2, 31))
                return 0;
        }
        return (int)res;
    }
};

int main()
{
    int a = -2147483412, b = -123, c = 120000, d = 2534236469, e = 100000002;
    Solution s;
    int aa, bb, cc, dd, ee;
    aa = s.reverse(a);
    bb = s.reverse(b);
    cc = s.reverse(c);
    dd = s.reverse(d);
    ee = s.reverse(e);

    int test = 9646324351;
    return 0;
}

