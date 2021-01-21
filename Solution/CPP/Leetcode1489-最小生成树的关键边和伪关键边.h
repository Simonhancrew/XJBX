#include <vector>
#include <algorithm>
using namespace std;
class UnionFind{
public:
    UnionFind(int n){
        parent.resize(n,0);
        for (int i  = 0;i < n;++i){
            parent[i] = i;
        }
        rank.resize(n,1);
        Area = n;
    }
    int find(int x){
        if (x == parent[x]){
            return x;
        }
        parent[x] = find(parent[x]);
        return parent[x];
    }
    bool _union(int x,int y){
        int fx = find(x),fy = find(y);
        if (fx == fy){
            return false;
        }
        --Area;
        if(rank[fx] < rank[fy]){
            swap(fx,fy);
        }
        parent[fy] = fx;
        rank[fx] += rank[fy];
        return true;
    }
    int Area;
private:
    vector<int> parent;
    vector<int> rank;
}; 
class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        
        //所有的边数
        int m = edges.size();
        for(int i = 0;i < m;++i){
            edges[i].push_back(i);
        }
        sort(edges.begin(),edges.end(),[](auto &u,auto &v){return u[2] < v[2];});
        int value = 0;
        //最小生成树的value计算出来
        for(int i = 0;i < m;i++){
            if(uf._union(edges[i][0],edges[i][1])){
                value += edges[i][2];
            }
        }
        vector<vector<int>> ans(2);
        //遍历每个边，判断关键和伪
        for(int i = 0;i < m;i++){
            //新的并查集
            int v = 0;
            UnionFind uf_cur(n);
            //在所有的边中，不加入i边的话，能不能最小生成合适的答案
            for(int j = 0;j < m;j++){
                if(i != j && uf_cur._union(edges[j][0],edges[j][1])){
                    v += edges[j][2];
                }
            }
            //是关键边就不用继续下去了
            if(uf_cur.Area != 1 || uf_cur.Area == 1 && v > value){
                ans[0].push_back(edges[i][3]);
                continue;
            }
            //是不是伪关键边就首先直接考虑他，直接加他加入并查集
            uf_cur = UnionFind(n);
            uf_cur._union(edges[i][0],edges[i][1]);
            v = edges[i][2];
            for(int j = 0;j < m;j++){
                if(j != i && uf_cur._union(edges[j][0],edges[j][1])){
                    v += edges[j][2];
                }
            }
            if(v == value){
                ans[1].push_back(edges[i][3]);
            }
        }
        return ans;
    }
};