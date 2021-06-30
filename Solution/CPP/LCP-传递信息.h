#include <vector>

using namespace std;

// 建图，深搜，满足条件，告辞

class Solution {
public:
    int ans = 0;
    int st,end;
    vector<vector<int>> edges;
    int numWays(int n, vector<vector<int>>& relation, int k) {
        edges.resize(n);
        for(auto way:relation){
            edges[way[0]].push_back(way[1]);
        }
        st = k;
        end = n - 1;
        dfs(0,0);
        return ans;
    }
    void dfs(int idx,int steps){
        if(steps == st){
            if(idx == end){
                ans++;
            }
            return;
        }
        for(auto dst:edges[idx]){
            dfs(dst,steps + 1);
        }
    }
};