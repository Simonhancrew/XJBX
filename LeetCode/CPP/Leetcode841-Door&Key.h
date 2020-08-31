#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms) {
        canReach.insert(0);
        DFS(rooms,0);
        for(int i = 0;i<rooms.size();i++){
            if(canReach.find(i)==canReach.end()){
                return false;
            }
        }
        return true;
    }
private:
    unordered_set<int> canReach;
    void DFS(const vector<vector<int>> &rooms,int index){
        for(auto room:rooms[index]){
            if(canReach.find(room) == canReach.end()){
                canReach.insert(room);
                DFS(rooms,room);
            }            
        }
    }
};
//BFS
#include <queue>
class Solution2 {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size(), num = 0;
        vector<int> vis(n);
        queue<int> que;
        vis[0] = true;
        que.emplace(0);
        while (!que.empty()) {
            int x = que.front();
            que.pop();
            num++;
            for (auto& it : rooms[x]) {
                if (!vis[it]) {
                    vis[it] = true;
                    que.emplace(it);
                }
            }
        }
        return num == n;
    }
};