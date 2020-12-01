#include <vector>
using namespace std;
class Solution {
public:
    void dfs(int node,int c,vector<vector<int>> graph){
        color[node] = c;
        int cNei = (c==RED?GREEN:RED);
        for(int neighbor:graph[node]){
            if(color[neighbor] == UNCOLORED){
                dfs(neighbor,cNei,graph);
                if(!valid){
                    return;
                }
            }else if(color[neighbor]!=cNei){
                valid = false;
                return;
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        color.assign(n, UNCOLORED);
        valid = true;
        for(auto i=0;i<n && valid;i++){
            if(color[i]==UNCOLORED){
                dfs(i,RED,graph);
            }
            
        }
        return valid;
    }
private:
    static constexpr int UNCOLORED = 0;
    static constexpr int RED = 1;
    static constexpr int GREEN = 2;
    vector<int> color;
    bool valid;
};