#include <vector>
#include <string>
using namespace std;
//利用并查集处理，格子四个点。
class Solution {
public:
    vector<int> f;

    int find(int x) {
        return x==f[x] ? x : f[x]=find(f[x]);
    }

    int merge(int u, int v) {
        int fu = find(u), fv = find(v);
        if (fu == fv) return 0;
        f[fv] = fu;
        return 1;
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        f = vector<int>((n+1)*(n+1), 0);
        for (int i = 0; i < (n+1)*(n+1); ++i) {
            f[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            merge(i, i+1);
            merge(n*(n+1)+i, n*(n+1)+i+1);
            merge(i*(n+1), (i+1)*(n+1));
            merge(i*(n+1)+n, (i+1)*(n+1)+n);
        }
        int cnt = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == ' ') continue;
                int u, v;
                if (grid[i][j] == '/') {
                    u = i*(n+1)+j+1;
                    v = (i+1)*(n+1)+j;
                } else {
                    u = i*(n+1)+j;
                    v = (i+1)*(n+1)+j+1;
                }
                if (!merge(u, v)) cnt++;
            }
        }
        return cnt;
    }
};