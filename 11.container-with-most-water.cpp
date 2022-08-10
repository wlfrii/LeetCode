#include "myfunctions.h"
/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 * 
 * Idea. 
 *   1. Using two index represent the start and end position in a vector.
 *   2. start from the begin, end from the end. calc the area between start and end first.
 *   3. then, move start or end by determining the area.
 * 
 */
class Solution {
public:
    // Method 1 --- 1036 ms	9.7 MB
    // int maxArea(vector<int>& height) {
    //     if(height.size() == 2)
    //         return min(height[0], height[1]);

    //     size_t area(0), idx1(0);
    //     while(idx1 < height.size() - 1)
    //     { 
    //         size_t idx2 = idx1 + 1;
    //         while(idx2 < height.size())
    //         {
    //             area = area > min(height[idx1], height[idx2])*(idx2-idx1) ? area : min(height[idx1], height[idx2])*(idx2-idx1);
    //             idx2++;
    //         }
    //         idx1++;
    //     }
    //     return area;
    // }

    // Method 2 --- 20 ms	9.7 MB
    int maxArea(vector<int>& height) {
        if(height.size() == 2)
            return min(height[0], height[1]);

        size_t area(0), start(0), end(height.size() - 1);
        while(start < end)
        {
            area = area > min(height[start], height[end]) * (end - start) ? area : min(height[start], height[end]) * (end - start);
            if (height[start] > height[end])
                end--;
            else if(height[start] < height[end])
                start++;
            else
            {
                if(height[start + 1] >= height[end - 1])
                    start++;
                else
                    end--;
            } 
        }
        return area;
    }
};

int main()
{
    vector<int> v1,v2,v3,v4,v5;
    v1 = lf::createVectorInt(9,1,8,6,2,5,4,8,3,7);
    v2 = lf::createVectorInt(10,9,3,5,6,7,8,1,3,4,2);
    v3 = lf::createVectorInt(10,5,3,5,6,7,8,1,3,4,2);
    v4 = lf::createVectorInt(4,2,8,8,2);
    v5 = lf::createVectorInt(4,1,2,4,3);

    Solution sln;

    int res1,res2,res3,res4,res5;
    res1 = sln.maxArea(v1);
    res2 = sln.maxArea(v2);
    res3 = sln.maxArea(v3);
    res4 = sln.maxArea(v4);
    res5 = sln.maxArea(v5);

    return 0;
}

