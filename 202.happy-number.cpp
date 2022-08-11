#include "myfunctions.h"

/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> res;
        res.insert(n);
        while(true){
            int sum = 0;
            while(n){
                int val = n % 10;
                sum += val*val;
                n = floor(n / 10);
            }
            if(sum == 1) return true;
            if(res.find(sum) != res.end()) return false;
            res.insert(sum);

            n = sum;
        }
    }
};

int main()
{
    Solution s;
    bool ret = s.isHappy(19);

    return 0;
}

// @lc code=end

