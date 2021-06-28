#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// BFS构建图的思路：首先遍历一下，找到起点的路线，将这个距离设置为1，然后队列中加入这条路线。
// 还要维护一个点的信息，看看每个点上挂了那几条路线。之后就可以根据路线 -> 点 -> 路线的思路去宽搜了
// 之后BFS这个路线，只要路线的距离更小，就更新他（代表的是做了几条公交），然后在点的信息中删除这个点,代表以后我一定不走回头路.
// 加速bfs

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        unordered_map<int,vector<int>> g;
        queue<int> que;
        int n = routes.size();
        vector<int> dist(n,1e8);
        for(int i = 0;i < n;++i){
            for(auto x:routes[i]){
                if(x == source){
                    dist[i] = 1;
                    que.push(i);
                }
                g[x].push_back(i);
            }
        }

        while(que.size()){
            auto t = que.front();
            que.pop();
            for(auto x:routes[t]){
                if(x == target) return dist[t];
                for(auto y:g[x]){
                    if(dist[y] > dist[t] + 1){
                        dist[y] = dist[t] + 1;
                        que.push(y);
                    }
                }
                g.erase(x);
            }
        }
        return -1;
    }
};