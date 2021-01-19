#include <vector>
#include <algorithm>
using namespace std;
//最小生成树kruskal,一种基于贪心的算法，
//从连接的边边长小到大，如果二者没有联通，就联通，之后加入图
//二者联通的话，不去考虑
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //曼哈顿距离
        auto manhattan_dist = [&](int x,int y) -> int{
            return abs(points[x][0] - points[y][0]) + abs(points[x][1] - points[y][1]);
        };
        //构建并查集
        int n = points.size();
        parent.resize(n,0);
        for(int i = 0;i < n;i++){
            parent[i] = i;
        }
        //对于每个点，构建他和他之后点关系的图
        vector<Edge> edges;
        for(int i = 0;i < n;i++){
            for(int j = i+1;j<n;j++){
                edges.emplace_back(manhattan_dist(i,j),i,j);
            }
        }
        //按照曼哈顿距离排序
        sort(edges.begin(),edges.end(),[](Edge a,Edge b){return a.len < b.len;});
        int ans = 0,num = 1;
        //如果不联通的话加入图中
        for(auto edge:edges){
            if(_union(edge.x,edge.y)){
                ans += edge.len;
                num++;
                if(num == n){
                    break;
                }
            }
        }
        return ans;
    }
private:
    vector<int> parent;
    int find(int x){
        if(parent[x] == x){
            return x;
        }
        parent[x] = find(parent[x]);
        return parent[x];
    }
    bool _union(int x,int y){
        int fx = find(x);
        int fy = find(y);
        if(fx == fy){
            return false;
        }
        parent[fy] = fx;
        return true;
    }
    struct Edge {
        int len, x, y;
        Edge(int len, int x, int y) : len(len), x(x), y(y) {}
    };
};