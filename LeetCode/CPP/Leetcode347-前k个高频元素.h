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
        //还可以使用operator()构建comparison,graeter本来就是一个类里有一个operator（）的重载
        class myComparison{
            bool operator()(const pair<int,int> &lhs,const pair<int,int> &rhs){
                return lhs.second>rhs.second;
            }
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> q(cmp);
        //priority_queue<pair<int,int>,vector<pair<int,int>>,myComparison> q;
        for(auto fre:occur){
            if(q.size() == k){
                if(q.top().second<fre.second){
                    q.pop();
                    q.push(fre);
                }
            }else{
                q.push(fre);
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