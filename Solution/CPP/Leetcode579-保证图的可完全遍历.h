#include <vector>
using namespace std;
class UnionFind{
public:
    UnionFind(int n){
        parent.resize(n,0);
        for(int i = 0;i < n;++i){
            parent[i] = i;
        }
        Area = n;
        rank.resize(n,1);
    }
    
    int find(int x){
        if(parent[x] == x){
            return x;
        }
        parent[x] = find(parent[x]);
        return parent[x];
    } 

    bool _union(int x,int y){
        int fx = find(x),fy = find(y);
        if(fx == fy){
            return false;
        }
        if(rank[fx] < rank[fy]){
            swap(fx,fy);
        }
        parent[fy] = fx;
        rank[fx] += rank[fy];
        --Area;
        return true;
    }
    int Area;
private:
    vector<int> parent;
    vector<int> rank;
};
//逆向思考，先找到连接的边，不需要连接的边出现++
//公共边的自由度更大，贪心的考虑公共边
//先连接公共边，再连接独占边
//如果连接的时候已经是联通的了，不连接
//可以删除的边+1
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        if(edges.size() < n-1){
            return -1;
        }
        UnionFind uf_bob(n),uf_alice(n);
        int ans = 0;
        //更改一下编号，从0开始
        for(auto &edge:edges){
            --edge[1];
            --edge[2];
        }
        for(auto edge:edges){
            if(edge[0] == 3){
                if(!uf_bob._union(edge[1],edge[2])){
                    ans++;
                }else{
                    uf_alice._union(edge[1],edge[2]);
                }
            }    
        }
        //连接独占边
        for(auto edge:edges){
            if(edge[0] == 1){
                //alice独占
                if(!uf_alice._union(edge[1],edge[2])){
                    ans++;
                }
            }else if(edge[0] == 2){
                //bob独占
                if(!uf_bob._union(edge[1],edge[2])){
                    ans++;
                }
            }
        }
        if(uf_alice.Area != 1 || uf_bob.Area != 1){
            return -1;
        }
        return ans;
    }
};