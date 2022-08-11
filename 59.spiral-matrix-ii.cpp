#include <vector>
using std::vector;

/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
public:
    
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0)); 
        int startx = 0, starty = 0;
        int loop = n / 2; 
        int mid = n / 2; 
        int count = 1; 
        int offset = 1; 
        int i,j;
        while (loop--) {
            i = startx;
            j = starty;

            
            for (j = starty; j < n - offset; j++) {
                ret[startx][j] = count++;
            }
            for (i = startx; i < n - offset; i++) {
                ret[i][j] = count++;
            }
            for (; j > starty; j--) {
                ret[i][j] = count++;
            }
            for (; i > startx; i--) {
                ret[i][j] = count++;
            }

            startx++;
            starty++;

            offset += 1;
        }

        // 如果n为奇数的话，需要单独给矩阵最中间的位置赋值
        if (n % 2) {
            ret[mid][mid] = count;
        }
        return ret;
    }
};

int main()
{
    Solution s;
    auto ret = s.generateMatrix(4);

    return 0;
}

// @lc code=end

