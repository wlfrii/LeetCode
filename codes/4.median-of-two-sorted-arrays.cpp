#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        unsigned int size1 = nums1.size();
        unsigned int size2 = nums2.size();
        if (size1 == 0)
            return size2 % 2 == 0 ? (double)(nums2[size2 / 2] + nums2[size2 / 2 - 1]) / 2.0 : nums2[floor(size2 / 2)];
        if (size2 == 0)
            return size1 % 2 == 0 ? (double)(nums1[size1 / 2] + nums1[size1 / 2 - 1]) / 2.0 : nums1[floor(size1 / 2)];

        unsigned int i(0), j(0);
        vector<int> all; // 思路：将两个vector从小到大排列，排到Medium处判断返回
        while (i < size1 || j < size2)
        {
            if (i < size1 && j < size2)
            {
                if (nums1[i] >= nums2[j])
                {
                    all.push_back(nums2[j]);
                    j++;
                }
                else
                {
                    all.push_back(nums1[i]);
                    i++;
                }
            }
            else
            {
                if (j == size2)
                {
                    all.push_back(nums1[i]);
                    i++;
                }
                else if (i == size1)
                {
                    all.push_back(nums2[j]);
                    j++;
                }
            }
            if (all.size() == ((size1 + size2) / 2 + 1) && (size1 + size2) % 2 == 0)
                return (double)(all[all.size() - 1] + all[all.size() - 2]) / 2.0;
            if (all.size() == ((size1 + size2 + 1) / 2) && (size1 + size2) % 2 == 1)
                return all[all.size() - 1];
        }
        return 0;
    }
};

int main()
{
    Solution sln;
    int a[] = { 2 };
	int b[] = { 1, 3 };
	vector<int> num1(a, a + sizeof(a) / sizeof(int));
	vector<int> num2(b, b + sizeof(b) / sizeof(int));
	double res = sln.findMedianSortedArrays(num1, num2);

	int a1[] = { 1, 2 };
	int b1[] = { 2, 4 };
	vector<int> num11(a1, a1 + sizeof(a1) / sizeof(int));
	vector<int> num12(b1, b1 + sizeof(b1) / sizeof(int));
	double res1 = sln.findMedianSortedArrays(num11, num12);

	int a2[] = { 1, 3 };
	//int b2[] = {  };
	vector<int> num21(a2, a2 + sizeof(a2) / sizeof(int));
	vector<int> num22;
	double res2 = sln.findMedianSortedArrays(num22, num21);

	int a3[] = { 2 };
	int b3[] = { -2, -1 };
	vector<int> num31(a3, a3 + sizeof(a3) / sizeof(int));
	vector<int> num32(b3, b3 + sizeof(b3) / sizeof(int));
	double res3 = sln.findMedianSortedArrays(num31, num32);

	int a4[] = { 1, 2, 3, 4, 5, 6 };
	int b4[] = { -2, -1 };
	vector<int> num41(a4, a4 + sizeof(a4) / sizeof(int));
	vector<int> num42(b4, b4 + sizeof(b4) / sizeof(int));
	double res4 = sln.findMedianSortedArrays(num41, num42);

	return;
}
