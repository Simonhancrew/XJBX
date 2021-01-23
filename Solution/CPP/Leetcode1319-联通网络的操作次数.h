#include <vector>
#include <unordered_set>
using namespace std;
class UnionFind{
public:
    vector<int> size;
    int Area;
    UnionFind(int n):parent(n),Area(n),size(n){
        for(int i = 0;i < n;i++){
            parent[i] = i;
        }
        for(int i = 0;i < n;i++){
            size[i] = 1;
        }
    }

    int find(int x){
        if(parent[x] == x){
            return x;
        }
        parent[x] = find(parent[x]);
        return parent[x];
    }

    void _union(int x,int y){
        int fx = find(x),fy = find(y);
        if(fx == fy){
            return;
        }
        if(size[fx] < size[fy]){
            swap(fx,fy);
        }
        --Area;
        parent[fy] = parent[fx];
        size[fx] += size[fy];
    }
private:
    vector<int> parent;
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        UnionFind uf(n);
        unordered_set<int> uset;
        for(auto conn:connections){
            uset.insert(conn[0]);
            uset.insert(conn[1]);
            if(uf.find(conn[0]) == uf.find(conn[1])){
                continue;
            }
            uf._union(conn[0],conn[1]);
        }
        if(uf.Area == 1){
            return 0;
        }
        int m = uset.size();
        int edges = connections.size();
        if(edges - uf.Area + 1 >= m - 1){
            return uf.Area - 1;
        }
        return -1;
    }
};