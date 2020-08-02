//优先级队列维护每行走到的最小，同时继续向前走，并且维护当前所有位置的最大值
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int leftrange = 0,rightrange = INT_MAX;
        int size = nums.size();
        vector<int> next(size);

        auto cmp = [&](const int &u,const int& v){
            return nums[u][next[u]]>nums[v][next[v]];
        };

        priority_queue<int,vector<int>,decltype(cmp)> pq(cmp);
        int minValue = 0,maxValue  = INT_MIN;
        for(int i =0;i<size;i++){
            pq.emplace(i);
            maxValue = max(maxValue,nums[i][0]);
        }

        while(true){
            int row = pq.top();
            pq.pop();
            minValue = nums[row][next[row]];
            if(maxValue-minValue <rightrange - leftrange){
                rightrange = maxValue;
                leftrange = minValue;
            }
            if(next[row] == nums[row].size()-1){
                break;
            }
            next[row]++;
            maxValue = max(maxValue,nums[row][next[row]]);
            pq.emplace(row);
        }
        return {leftrange,rightrange};
    }
};