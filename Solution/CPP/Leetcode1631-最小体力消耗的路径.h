#include <vector>
#include <queue>
using namespace std;
//最短路算法Dijkstra,不适用有负权边
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(),n = heights[0].size();
        //从0到每个点的最小距离，是一步步更新
        vector<int> dist(m*n,INT_MAX);
        dist[0] = 0;
        auto tmpfunc = [](const auto& e1,const auto &e2){
            auto&& [x1,y1,d1] = e1;
            auto&& [x2,y2,d2] = e2;
            return d1 > d2;
        };
        //利用最小堆去处理当前联通的最小距离
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,decltype(tmpfunc)> q(tmpfunc);
        q.emplace(0,0,0);
        //访问过的数组
        vector<int> seen(m*n,0);
        //本质上有BFS的意思，遍历下一层的节点，并且最小堆的顶部记录的就是当前层和下一层的最小距离
        //会有一个松弛操作
        while(!q.empty()){
            auto [x,y,d] = q.top();
            q.pop();
            int id = x * n + y;
            if(seen[id]){
                continue;
            }
            if(x == m - 1 && y == n - 1){
                break;
            }
            //找过了，防止死循环
            seen[id] = 1;
            //对于四个方向，给他松弛一下，看看能不能更新
            for(int i = 0;i < 4;i++){
                int nx = x + direction[i][0];
                int ny = y + direction[i][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && max(d,abs(heights[x][y] - heights[nx][ny])) < dist[nx * n + ny]){
                    dist[nx*n + ny] = max(d,abs(heights[x][y] - heights[nx][ny]));
                    q.emplace(nx,ny,dist[nx * n + ny]);
                }
            }

        } 
        return dist[m * n -1];
    }
private:
    static constexpr int direction[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
};