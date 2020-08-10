#include "string"
using std::string;

/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 * 
 * Idea.
 *   举例: "abccccbc", 中间一段相同的"c"都属于palindrome string, 对于相同的一段，应该视其为一个值，即此时此刻的回文中心. 然后基于此中心，向两侧再找.
 */
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1)
            return s;
        
        int idx = 0, start_idx = 0, idx_len = 1;
        while(idx < s.size() && (s.size() - idx) > (idx_len / 2))
        {
            int l_idx = idx - 1;
            while(idx < s.size() && s[idx] == s[idx + 1])
            {
                idx++;
            }
            idx++;
            int r_idx = idx;
            while(l_idx >= 0 && r_idx < s.size() && s[l_idx] == s[r_idx])
            {
                l_idx--;
                r_idx++;
            }
            if(r_idx - l_idx - 1 > idx_len)
            {
                idx_len = r_idx - l_idx - 1;
                start_idx = l_idx + 1;
            }           
        }
        return s.substr(start_idx, idx_len);
    }
};

int main()
{
    string s1, s11("babac");
    string s2, s22("cddb");
    string s3, s33("bbccdd");
    string s4, s44("bccddbb");
    string s5, s55("qwertttrewq");
    string s6, s66("aabbcccbba");
    string s7, s77("aaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaaaaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaa");
    Solution sln;
    s1 = sln.longestPalindrome(s11);
    s2 = sln.longestPalindrome(s22);
    s3 = sln.longestPalindrome(s33);
    s4 = sln.longestPalindrome(s44);
    s5 = sln.longestPalindrome(s55);
    s6 = sln.longestPalindrome(s66);
    s7 = sln.longestPalindrome(s77);

    return 0;
}
