#include <vector>
#include <unordered_map>
using namespace std;
//建图加深搜
class Solution {
public:
    void DFS(int index,vector<vector<int>> &edges,vector<int> &vis){
        vis[index] = 1;
        for(auto &y:edges[index]){
            if(vis[y] == 0){
                DFS(y,edges,vis);
            }

        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> edges(n,vector<int>{});
        for (int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(i == j){
                    continue;
                }
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    edges[i].push_back(j);
                }
            }
        }
        vector<int> vis(n);
        int num = 0;
        for(int i = 0; i < n;i++){
            if(!vis[i]){
                num++;
                DFS(i,edges,vis);
            }
        }
        //要的是可以删去的数量
        return n - num;
    }
};


//并查集，优化建图
//之前这个图中，每一列每一行的每一个值是互相连接的
//我想在考虑他是一颗树，有头节点，就是stone第一次遍历到该行该列的作为头
//此时可以考虑并查集
//对于行列的处理，它是由大小限制的，我把行列关联起来
//行列都是小于10000的，那就把列看成10000开始的
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        for(int i = 0;i < n;i++){
            _union(stones[i][0],stones[i][1] + 10001);
        }
        int ans = 0;
        for(auto par:uf){
            if(par.first == par.second){
                ans++;
            }
        }
        return n - ans;
    }
    int find(int i){
        if(uf.count(i) == 0){
            uf[i] = i;
        }
        return uf[i] == i?i:uf[i] = find(uf[i]);
    }
    void _union(int lhs,int rhs){
        int frhs = find(rhs),flhs = find(lhs);
        if(frhs == flhs){
            return;
        }
        uf[frhs] = flhs; 
    }
private:
    unordered_map<int,int> uf;
};