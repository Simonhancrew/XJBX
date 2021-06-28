#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

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