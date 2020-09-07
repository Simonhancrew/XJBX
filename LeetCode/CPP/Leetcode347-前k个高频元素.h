#include <vector>
#include <map>
#include <queue>
#include <unordered_map>
#include <algorithm>  
#include <utility>
using namespace std;
//topk一般都可以用最小堆
//一张哈希表映射出现次数
//最小堆按pair的第二个储存
//遍历之后将其放入数组
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        if(nums.size() == 1){
            result.push_back(nums[0]);
            return result;
        }
        unordered_map<int,int> occur;
        for(auto k:nums){
            occur[k]++;
        }
        auto cmp = [](pair<int,int> &m,pair<int,int> &n){
            return m.second>n.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> q(cmp);
        for(auto [num,count]:occur){
            if(q.size() == k){
                if(q.top().second<count){
                    q.pop();
                    q.push({num,count});
                }
            }else{
                q.push({num,count});
            }
        }
        while(!q.empty()){
            result.push_back(q.top().first);
            q.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};