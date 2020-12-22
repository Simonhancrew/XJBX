#include <vector>
#include <algorithm>
using namespace std;
//按照右边界排序，就要从左向右遍历，因为右边界越小越好，
//只要右边界越小，留给下一个区间的空间就越大，
//所以从左向右遍历，优先选右边界小的
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0){
            return 0;
        }
        sort(intervals.begin(),intervals.end(),[](vector<int> lhs,vector<int> rhs){
            return lhs[1] < rhs[1];
        });
        //右边界排序之后，局部最优：优先选右边界小的区间，所以从左向右遍历，留给下一个区间的空间大一些，从而尽量避免交叉。
        //全局最优：选取最多的非交叉区间。
        int cnt = 1;//记录非交叉区间的个数
        int curborder = intervals[0][1];//此时的右边界
        for(int i = 1;i < intervals.size();++i){
            if (intervals[i][0] >= curborder){
                curborder = intervals[i][1];
                cnt++;
            }
        }
        return intervals.size() - cnt;
    }
};