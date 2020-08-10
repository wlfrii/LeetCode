#include <string>
using std::string;
/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       	if (s.length() == 0)
            return 0;
        if (s.length() == 1)
            return 1;

        int i = 0, j = 1, counts = 1;
        while (j < s.size())
        {
            bool a = false;
            int t = i;
            for (t; t < j; t++)
            {
                if (s[t] == s[j])
                {
                    a = true;
                    break;
                }
            }
            if (a == true)
                i = t + 1;
            else
                counts = counts > j - i + 1 ? counts : j - i + 1;
            j++;
        }
        return counts;
    }
};

// int main()
// {
//     Solution sln;
//     string s("abcabcbb");
// 	int a = sln.lengthOfLongestSubstring(s);
// 	s = "pwwkew";
// 	int b = sln.lengthOfLongestSubstring(s);
// 	s = "bbbbbb";
// 	int c = sln.lengthOfLongestSubstring(s);
// 	s = "qwertyuiop";
// 	int d = sln.lengthOfLongestSubstring(s);
// 	s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~  abcdefghijklmnopqrstuvwxyzABCD";
// 	int e = sln.lengthOfLongestSubstring(s);

// 	return 0;
// }

