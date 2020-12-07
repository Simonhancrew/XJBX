#include <vector>
#include <algorithm>
using namespace std;
//复杂度很高rclog(rc)
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R,int C,int r0,int c0){
        vector<vector<int>> res;
        int i = 0,end = R*C;
        for(int i = 0;i < R;++i){
            for(int j = 0;j < C;++j){
                res.push_back({i,j});
            }
        }
        sort(res.begin(),res.end(),[&](vector<int> a,vector<int> b){
            return (abs(a[0] - r0) + abs(a[1] - c0) < abs(b[0] - r0) + abs(b[1] - c0));
        });
    }
};

//桶排序
class Solution {
public:
    int dist(int r1,int c1,int r2,int c2){
        return abs(r1 - r2) + abs(c1 - c2);
    }
    vector<vector<int>> allCellDistOrder(int R,int C,int r0,int c0){
        //算出需要的桶数
        int maxDist = max(r0,R-1-r0) + max(c0,C-1-c0);
        vector<vector<vector<int>>> bucket(maxDist+1);
        for(int i = 0;i < R;++i){
            for(int j = 0;j < C;++j){
                //计算桶的index
                int index = dist(i,j,r0,c0);
                bucket[index].push_back({i,j});
            }
        }
        vector<vector<int>> res;
        for(int i = 0;i <= maxDist;++i){
            for(auto point:bucket[i]){
                res.push_back(point);
            }
        }
        return res;
    }
};