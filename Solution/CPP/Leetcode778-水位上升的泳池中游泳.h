#include <vector>
#include <queue>
using namespace std;
//还是dij求最短通路
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        auto tmpfunc = [](const auto &lhs,const auto &rhs){
            auto&& [x1,y1,val1] = lhs;
            auto&& [x2,y2,val2] = rhs;
            return val1 > val2;
        };

        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,decltype(tmpfunc)> q(tmpfunc);
        q.emplace(0,0,grid[0][0]);
        vector<vector<int>> seen(n,vector<int>(n,0));
        int ans = 0;
        while(!q.empty()){
            auto [i,j,val] = q.top();
            q.pop();
            if(seen[i][j] == 1){
                continue;
            }
            seen[i][j] = 1;
            ans = max(ans,val); 
            if(i == n-1 && j == n - 1){
                break;
            }
            for (int d = 0;d < 4;d++){
                int nx = i + direction[d][0],ny = j + direction[d][1];
                if(nx >= 0 && nx < n && ny >=0 && ny <n){
                    if(seen[nx][ny] == 0){
                        q.push({nx,ny,grid[nx][ny]});
                    }
                }
            }
        }
        return ans;
    }
private:
    static constexpr int direction[4][2] = {{1,0},{-1,0},{0,1},{0,-1}}; 
};