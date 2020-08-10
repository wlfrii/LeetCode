#include <vector>
using std::vector;

/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = i+1; j < nums.size(); ++j)
            {
                if(nums[i] + nums[j] == target)
                {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        res.push_back(0);
        return res;
    }
};
// #include <iostream>
// int main()
// {
//     printf("test");
//     Solution s;
//     int nums[] = {2,7,11,15};
//     vector<int> n(nums, nums + sizeof(nums)/sizeof(int));
//     vector<int> res = s.twoSum(n, 9);
//     std::cout << "test" << std::endl;
//     return 0;
// }
