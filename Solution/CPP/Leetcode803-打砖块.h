#include <vector>
using namespace std;
//需要反向思考，如果使用并查集
//首先并查集是合并两个连通分区的
//此处砖块破碎，需要分离，所以可以逆序使用
class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        //此处可以做grid的拷贝
        auto copy = grid;
        int n = hits.size();
        vector<int> ans(n, 0);
        row = copy.size();
        col = copy[0].size();
        int size = row * col;
        //特殊位置多一个，这个位置就是顶部x，位置为size
        parent.resize((long long)size + 1, 0);
        for (int i = 0; i < size + 1; i++) {
            parent[i] = i;
        }
        rank.resize((long long)size + 1, 1);
        //将hint数组中在grid内的砖块全部置零
        for (auto hit : hits) {
            copy[hit[0]][hit[1]] = 0;
        }
        //从hits的最后一个砖块算起，看有多少因为添加了砖块与顶部相连    
        //将第一行的1和并查集多的顶部相连
        for (int i = 0; i < col; i++) {
            if (copy[0][i] == 1) {
                _union(size, i);
            }
        }

        //连通一下每个点的区域，以为是递增往下右的，所以只用考虑两个方向
        for (int i = 1; i < copy.size(); i++) {
            for (int j = 0; j < copy[0].size(); j++) {
                if (copy[i][j] == 1) {
                    if (copy[i - 1][j] == 1) {
                        _union(getindex(i, j), getindex(i - 1, j));
                    }
                    if (j > 0 && copy[i][j - 1] == 1) {
                        _union(getindex(i, j), getindex(i, j - 1));
                    }
                }
            }
        }
        //补回砖块
        static const int directions[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
        for (int i = n - 1; i >= 0; i--) {
            int x = hits[i][0];
            int y = hits[i][1];
            if (grid[x][y] == 0) {
                continue;
            }
            //补回之前与顶部相连的砖块数
            int origin = get_size(size);
            if (x == 0) {
                _union(size, y);
            }
            //看一下四个方向的数
            for (auto direction : directions) {
                int prex = x + direction[0];
                int prey = y + direction[1];
                //因为没有按照小树往大树上合，所以方向不能反
                if (inArea(prex, prey) && copy[prex][prey] == 1) {
                    _union(getindex(prex, prey), getindex(x, y));
                }
            }
            //看一下现在有多少和顶部相连的区域
            int cur = get_size(size);
            ans[i] = max(0, cur - origin - 1);
            //不要忘记补回砖块
            copy[x][y] = 1;
        }
        return ans;
    }
    int getindex(int x, int y) {
        return x * col + y;
    }
    bool inArea(int x, int y) {
        return x >= 0 && y >= 0 && y < col && x < row;
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void _union(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx == fy) {
            return;
        }
        parent[fy] = fx;
        rank[fx] += rank[fy];
    }
    int get_size(int x) {
        int fx = find(x);
        return rank[fx];
    }
private:
    vector<int> parent;
    vector<int> rank;
    int col;
    int row;
};