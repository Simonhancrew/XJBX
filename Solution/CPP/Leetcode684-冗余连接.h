#include <vector>
using namespace std;
//无向有环图，有n个节点的话，也有n条边
//而无向无环图，n节点，n-1条边
//考虑采用并查集，顺序遍历整个邻接矩阵，如果之前这二者不是一个集合的，将其纳入树中
//如果此时二者已经在一个集合中了
//说明出现了环路
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        unionfind.resize(n+1,0);
        for(int i = 1;i <= n;i++){
            unionfind[i] = i;
        }
        for(auto edge:edges){
            int lhs = find(edge[0]);
            int rhs = find(edge[1]);
            if(lhs != rhs){
                _union(edge[0],edge[1]);
            }else{
                return edge;
            }
        }
        return vector<int>{};
    }
    int find(int index){
        if(index != unionfind[index]){
            unionfind[index] = find(unionfind[index]);    
        }
        return unionfind[index];
    }
    void _union(int lhs,int rhs){
        int fx = find(lhs);
        int fy = find(rhs);
        if(fx == fy){
            return;
        }
        unionfind[fy] = fx;
    }
private:
    vector<int> unionfind;
}; 