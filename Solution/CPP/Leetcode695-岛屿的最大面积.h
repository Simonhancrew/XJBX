#include <vector>
#include <algorithm>
//dfs搜索所有的点，不越界，不为0，没搜索过就可以加一
using namespace std;
class Solution {
public:
    
    int maxAreaOfIsland(vector<vector<int>> &grid){
        int m = grid.size(),n = grid[0].size();
        //记录已经搜索过的节点
        vector<vector<int>> map(m,vector<int>(n,0));
        int res = 0;
        for(int i =0;i < m;++i){
            for(int j = 0;j < n;++j){
                res = max(res,DFS(grid,i,j,map));
            }
        }
        return res;
    }
private:
    int DFS(vector<vector<int>> &grid,int i,int j,vector<vector<int>> &map){
        int m = grid.size(),n = grid[0].size();
        //边界和相关条件判断
        if(i < 0||i >= m||j < 0||j >= n||map[i][j] == 1 || grid[i][j] == 0){
            return 0;
        }
        map[i][j] = 1;
        int dx[4] = {0,0,-1,1};
        int dy[4] = {-1,1,0,0};
        //深搜
        int ans = 1;
        for(int index = 0;index < 4;++index){
            int nx = i + dx[index],ny = j + dy[index];
            ans += DFS(grid,nx,ny,map);
        }
        return ans; 
    }
};

//压栈
#include <stack>
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i != grid.size(); ++i) {
            for (int j = 0; j != grid[0].size(); ++j) {
                int cur = 0;
                stack<int> stacki;
                stack<int> stackj;
                stacki.push(i);
                stackj.push(j);
                while (!stacki.empty()) {
                    int cur_i = stacki.top(), cur_j = stackj.top();
                    stacki.pop();
                    stackj.pop();
                    if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != 1) {
                        continue;
                    }
                    ++cur;
                    grid[cur_i][cur_j] = 0;
                    int di[4] = {0, 0, 1, -1};
                    int dj[4] = {1, -1, 0, 0};
                    for (int index = 0; index != 4; ++index) {
                        int next_i = cur_i + di[index], next_j = cur_j + dj[index];
                        stacki.push(next_i);
                        stackj.push(next_j);
                    }
                }
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};