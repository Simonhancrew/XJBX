#include <vector>
#include <string>
using namespace std;
class UnionFind{
public:
    int Area;
    UnionFind(int n):parent(n),rank(n),Area(n){
        for(int i = 0;i < n;i++){
            parent[i] = i;
            rank[i] = 1;
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
        if(rank[fx] < rank[fy]){
            swap(fx,fy);
        }
        parent[fy] = fx;
        rank[fx] += rank[fy];
        Area--;
    }
private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        UnionFind uf(n);
        for(int i = 0;i < n - 1;i++){
            for(int j = i + 1;j < n;j++){
                if(check(strs[i],strs[j],m)){
                    uf._union(i,j);
                }
            }
        }
        return uf.Area;
    }
private:
    bool check(string &lhs,string &rhs,int len){
        int num = 0;
        for(int i = 0;i < len;i++){
            if(rhs[i] != lhs[i]){
                num++;
            }
            if(num > 2){
                return false;
            }
        }
        return true;
    }
};