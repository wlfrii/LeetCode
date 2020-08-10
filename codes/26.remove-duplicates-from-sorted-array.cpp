#include "myFunctions.h"
/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */
class Solution {
public:
    // // Method 1
    // int removeDuplicates(vector<int>& nums) {
    //     if(nums.size() == 0)
    //         return 0;
    //     else if(nums.size() == 1)
    //         return 1;

    //     int idx = 1;
    //     while(idx < nums.size())
    //     {
    //         if(nums[idx - 1] == nums[idx])
    //         {
    //             nums.erase(nums.begin() + idx);
    //         }
    //         else
    //         {
    //             idx++;
    //         }
    //     }
    //     return idx;
    // }
    // Method 2
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;

        int i = 0, j = 1;
        while(j < nums.size())
        {
            if(nums[i] != nums[j])
                nums[++i] = nums[j];
            j++;
        }
        //nums.erase(nums.begin() + i + 1, nums.end());
        return i + 1;
    }
};

int main()
{
    vector<int> v1,v2,v3,v4;
    v1 = lf::createVectorInt(3,1,1,2);
    v2 = lf::createVectorInt(10,0,0,1,1,1,2,2,3,3,4);
    v3 = lf::createVectorInt(4, 0, 1, 2, 3);
    v4 = lf::createVectorInt(11,1,1,2,2,3,4,5,5,6,6,6);

    Solution sln;

    int res1 = sln.removeDuplicates(v1);
    int res2 = sln.removeDuplicates(v2);
    int res3 = sln.removeDuplicates(v3);
    int res4 = sln.removeDuplicates(v4);


    return 0;
}

