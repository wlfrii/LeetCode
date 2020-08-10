#include <string>
#include <vector>
using std::string;
using std::vector;
/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

/* Idea:
 * 1.不论怎么排列，总有一组括号是‘开闭’相邻的
 * 
 * ASCII        十进制
 *  '('           40
 *  ')'           41
 *  '{'          123
 *  '}'          125
 *  '['           91
 *  ']'           93
 */

// @lc code=start
class Solution {
public:
    // Version 1: Runtime: 104 ms, Memory: 6.1 MB
    /*bool isValid(string s)
    {
        // except the empty string
        if(s.empty()) return true;
        // except the odd num
        if(s.size() % 2 == 1) return false;
        // the number will be even
        while(!s.empty())
        {
            int pos = s.find(brackets[0]);
            if(pos != string::npos) 
                s.erase(pos, 2);
            else
            {
                pos = s.find(brackets[1]);
                if(pos != string::npos) 
                    s.erase(pos, 2);
                else
                {
                    pos = s.find(brackets[2]);
                    if(pos != string::npos) 
                        s.erase(pos, 2);
                    else
                        return false;
                }    
            }          
        }
        return true;
    }*/
    
    // Version 2: Runtime: 0 ms, Memory: 6.1 MB
    bool isValid(string s)
    {
        // except the empty string
        if(s.empty()) return true;
        // except the odd num
        if(s.size() % 2 == 1) return false;
        // except the string start with a close bracket
        if(s[0] == ')' || s[0] == '}' || s[0] == ']')
            return false;

        vector<char> stack;
        stack.push_back(s[0]);
        int idx = 0;
        while(++idx < s.size())
        {
            if(s[idx] == '(' || s[idx] == '{' || s[idx] == '[') {
                stack.push_back(s[idx]);
            }
            else
            {
                int tmp = static_cast<int>(s[idx]) - static_cast<int>(stack[stack.size()-1]);
                if(tmp > 0 && tmp <= 2)
                    stack.pop_back();
                else
                    return false;
            }    
        }
        if(stack.size() != 0) return false;

        return true;
    }
private:
    int match_start_brackets(char c)
    {
        if(c == '(') return 0;
        if(c == '{') return 1;
        if(c == '[') return 2;
        return -1;
    }    
    char brackets_start[3] = {'(', '{', '['};
    char brackets_close[3] = {')', '}', ']'};

    const string brackets[3] = {"()", "{}", "[]"};
};

// int main()
// {
//     enum{ NUM = 6 };
//     string str[NUM] = {
//         "()", "()[]{}", "(]", "([)]", "{[]}", "{{)}"
//     };

//     Solution sln;
//     bool res[NUM];
//     for(int i = 0; i < NUM; i++)
//     {
//         res[i] = sln.isValid(str[i]);
//     }

//     return 0;
// }
// @lc code=end