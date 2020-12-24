#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size();
        if(n == 0){
            return res;
        }
        sort(intervals.begin(),intervals.end(),[](vector<int> &lhs,vector<int> &rhs) {
            return lhs[0] < rhs[0];
        });
        bool flag = false;//最后一个去区间是否合并了
        for(int i = 1;i < n;++i){
            int start = intervals[i - 1][0];//因为这里单独的区间是i-1的
            int end = intervals[i - 1][1];
            while(i < n && end >= intervals[i][0]){//不断的合并区间
                end = max(end,intervals[i][1]);
                if(i == n - 1) flag == true;//最后一个区间有没有被合并
            }
            res.push_back({start,end});//此处和并的最多到 n -2 如果最后一个区间没有交集的话
        }
        if(flag == false){
            res.push_back(intervals[n - 1]);
        }
        return res;
    }
};


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size();
        if(n == 0){
            return res;
        }
        //按照左端点排序，看看右端点是否有交集
        sort(intervals.begin(),intervals.end(),[](vector<int> &lhs,vector<int> &rhs) {
            return lhs[0] < rhs[0];
        });
        res.push_back(intervals[0]);
        for(int i = 1;i < n;++i){
            //当前区间有交集就更新
            if(intervals[i][0] <= res.back()[1]){
                res.back()[1] = max(intervals[i][1],res.back()[1]);
            }else{
                //没有交集就直接push
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};