#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() < 2){
            if(stones.size() == 0){
                return 0;
            }else{
                return stones[0];
            }
        }
        int n = stones.size();
        sort(stones.begin(),stones.end());
        auto t1 = stones[n - 2],t2 = stones[n-1];
        stones.pop_back();
        stones.pop_back();
        stones.push_back(t1 + t2 - 2*t1);
        return lastStoneWeight(stones);
    }
};
//二者时间差不多，标准库的sort实在太强
#include <queue>
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for (auto s:stones){
            q.push(s);
        }
        while(q.size() > 1){
            auto t1 = q.top();
            q.pop();
            auto t2 = q.top();
            q.pop();
            if(t1 > t2){
                q.push(t1 - t2);
            }
        }
        return q.empty()?0:q.top();
    }
};