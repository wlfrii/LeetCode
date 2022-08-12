#include "myfunctions.h"
/*
 * @lc app=leetcode id=720 lang=cpp
 *
 * [720] Longest Word in Dictionary
 */
class Solution {
public:
    string longestWord(vector<string>& words) {
        int size = 0;
        string result;
        for(auto word : words) {
            int idx[26] = {0};
            for(auto ch : word) {
                idx[ch - 'a'] = 1;
            }
            // count
            int count = 0;
            for(int i = 0; i < 26; i++){
                count += idx[i];
            }
            if(count == size){
                int i = 0;
                while(i < result.size() && i < word.size()) {
                    int d = result[i] - word[i];
                    if(d < 0){
                        break;
                    }
                    else if(d > 0) {
                        result = word;
                        break;
                    }
                    i++;
                }
            }
            else if(count > size) {
                size = count;
                result = word;
            }
        }
        return result;
    }
};

int main()
{
    string s1[5] = {"w","wo","wor","worl", "world"};
    vector<string> vs1(s1, s1 + 5);

    string s2[7] = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    vector<string> vs2(s2, s2 + 7);

    string s3[13] = {"m", "mo", "moc", "moch", "mocha", "l", "la", "lat", "latt", "latte", "c", "ca", "cat"};
    vector<string> vs3(s3, s3 + 13);

    vector<string> test = lf::createVectorString(2, "h", "w");

    string res1, res2, res3, res4;
    Solution sln;
    // res1 = sln.longestWord(vs1);
    // res2 = sln.longestWord(vs2);
    res3 = sln.longestWord(vs3);


    return 0;
}
