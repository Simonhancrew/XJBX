#include <vector>
using namespace std;
//树型dp，面试常考
//dfs+记忆化
class Solution {
public:
    //sz代表子树节点数量
    vector<int> ans, sz, dp;
    //邻接矩阵
    vector<vector<int>> graph;

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        ans.resize(N, 0);
        sz.resize(N, 0);
        dp.resize(N, 0);
        graph.resize(N, {});
        for (auto& edge: edges) {
            int u = edge[0], v = edge[1];
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }
        dfs(0, -1);
        dfs2(0, -1);
        return ans;
    }
private:
    //当前节点和父节点
    void dfs(int u, int f) {
        //当前节点的规模最开始为1
        sz[u] = 1;
        //dp答案最开始0
        dp[u] = 0;
        for (auto& v: graph[u]) {
            if (v == f) {
                continue;
            }
            //深搜子结点v，得到v的结果dp[v]
            dfs(v, u);
            //根据推导公式u到各个节点的距离就等于他的孩子到其余节点的距离，加上每个节点的规模
            dp[u] += dp[v] + sz[v];
            //规模的确定
            sz[u] += sz[v];
        }
    }

    void dfs2(int u, int f) {
        //首先确定u
        ans[u] = dp[u];
        for (auto& v: graph[u]) {
            if (v == f) {
                continue;
            }
            //拷贝原来的值
            int pu = dp[u], pv = dp[v];
            int su = sz[u], sv = sz[v];
            //根据原理换根
            dp[u] -= dp[v] + sz[v];
            sz[u] -= sz[v];
            dp[v] += dp[u] + sz[u];
            sz[v] += sz[u];
            //对每个v也去深搜
            dfs2(v, u);
            //回溯恢复现场
            dp[u] = pu, dp[v] = pv;
            sz[u] = su, sz[v] = sv;
        }
    }
};