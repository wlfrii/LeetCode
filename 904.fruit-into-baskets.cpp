#include <vector>
using std::vector;


/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if(fruits.size() <= 2) return fruits.size();

        int t1 = 0;
        auto findT2 = [&fruits, &t1]() -> int{
            int i = t1 + 1;
            for(; i < fruits.size(); i++){
                if(fruits[i] != fruits[t1]){
                    return i;
                    break;
                }
            }
            return i - 1;
        };

        int t2 = findT2();      
        int ret = t2 - t1 + 1;

        int i = t2 + 1; 
        while (i < fruits.size()) {
            if(fruits[i] == fruits[t1] || fruits[i] == fruits[t2]){
                i++;
            }
            else {
                ret = ret > i - t1 ? ret : i - t1;
                t1 = t2;
                t2 = findT2();
                
                i = t2 + 1;
            }
        }
        ret = ret > i - t1 ? ret : i - t1;

        return ret;
    }
};

int main()
{
    vector<int> nums = {1,2,3,2,2,4,2,3,3,4,3,2};
    // vector<int> nums = {1,2,3,2,2};
    // vector<int> nums = {0,1,6,6,4,4,6};
    // vector<int> nums = {6,6,6,6,6,6};
    Solution s;
    int ret = s.totalFruit(nums);


    return 0;
}
// @lc code=end

