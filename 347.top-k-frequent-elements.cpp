#include "myfunctions.h"
/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:
    class Cmp{
    public:
        bool operator()(const pair<int, int>& p1, const pair<int, int>& p2){
            return p1.second > p2.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(auto& n : nums){
            map[n]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pri_que;
        unordered_map<int, int>::iterator it;
        for(it = map.begin(); it != map.end(); it++){
            pri_que.push(*it);
            if(pri_que.size() > k){
                pri_que.pop();
            }
        }

        vector<int> ret(k);
        for(int i = k - 1; i >= 0; i--){
            ret[i] = pri_que.top().first;
            pri_que.pop();
        }

        return ret;
    }
};

int main()
{
    Solution sln;

    vector<int> nums = {1,1,1,2,2,3};
    auto ret = sln.topKFrequent(nums, 2);

    return 0;
}

// @lc code=end

