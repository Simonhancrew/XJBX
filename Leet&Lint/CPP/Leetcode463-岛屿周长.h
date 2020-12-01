#include <vector>
using namespace std;
//因为确定了有岛屿，遍历每一个方块找四周邻近是岛还是湖就可以得到当前的边信息
class Solution {
public:
    constexpr static int dx[4] = {0,0,-1,1};
    constexpr static int dy[4] = {-1,1,0,0};
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        int res = 0;
        for(int i =0;i<m;++i){
            for(int j = 0;j<n;++j){
                int cnt = 0;
                if(grid[i][j] == 1){
                    for(int k =0;k<4;++k){
                        int nx = i+dx[k];
                        int ny = j+dy[k];
                        if(nx < 0||nx >= m||ny < 0||ny >= n||grid[nx][ny] == 0){
                            ++cnt;
                        }
                    }
                    res += cnt;
                }
            }
        }
        return res;
    }
};