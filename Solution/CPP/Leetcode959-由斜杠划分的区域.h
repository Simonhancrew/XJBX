//每个正方形分成4小块，遇到不同的符号合并03，12或者01，23.然后上下相邻的三角形合并
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> f;

    int find(int x) {
        return x==f[x] ? x : f[x]=find(f[x]);
    }

    void merge(int u, int v) {
        int fu = find(u), fv = find(v);
        if (fu == fv) return;
        f[fv] = fu;
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        f = vector<int>(4*n*n, 0);
        for (int i = 0; i < 4*n*n; ++i) {
            f[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                //当前到了那一个方块
                //s是当前第一三角格子
                int s = 4*(i*n+j);
                if (grid[i][j] == '/') {
                    merge(s, s+3);
                    merge(s+1, s+2);
                } else {
                    merge(s, s+1);
                    merge(s+2, s+3);
                }
                if (grid[i][j] == ' ') {
                    merge(s, s+3);
                }
                //合并上下左右的块联通
                if (i > 0) merge(s, s-4*n+2);
                if (i < n-1) merge(s+2, s+4*n);
                if (j > 0) merge(s+3, s-3);
                if (j < n-1) merge(s+1, s+7);
            }
        }
        int cnt = 0;
        for (int i = 0; i < 4*n*n; ++i) {
            if (find(i) == i) cnt++;
        }
        return cnt;
    }
};

