#include <vector>
using namespace std;
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