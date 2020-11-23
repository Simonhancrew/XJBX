#include <vector>
#include <algorithm>
using namespace std;
//先排序，再维护一个区间
class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &points){
        if(points.empty()){
            return 0;
        }
        sort(points.begin(),points.end(),[](vector<int> lhs,vector<int> rhs){
            return lhs[0] <= rhs[0];
        });
        int res = 1;
        int lhs = points[0][0],rhs = points[0][1];
        for(int i = 1;i < points.size();++i){
            if(points[i][0] > rhs){
                res++;
                lhs = points[i][0];
                rhs = points[i][1];
            }else if(rhs <= points[i][1]){
                lhs = points[i][0];
            }else{
                lhs = points[i][0];
                rhs = points[i][1];
            }
        }
        return res;
    }
};
//优化一下，排序加贪心
class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &points){
        if(points.empty()){
            return 0;
        }
        sort(points.begin(),points.end(),[](const vector<int> &lhs,const vector<int> &rhs){
            return lhs[1] < rhs[1];
        });
        int res = 1;
        int lhs = points[0][0],rhs = points[0][1];
        for(const auto& ballon:points){
            if(ballon[0] > rhs){
                rhs = ballon[1];
                res++;
            }
        }
        return res;
    }
};