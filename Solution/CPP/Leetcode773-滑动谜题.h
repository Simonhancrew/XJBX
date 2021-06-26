#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        typedef vector<vector<int>> VII; 
        vector<vector<int>> target = {{1,2,3},{4,5,0}};
        if(target == board) return 0;
        queue<VII> que;
        que.push(board);
        map<VII,int> dist;
        dist[board] = 0;
        int dx[4] = {0,0,-1,1},dy[4] = {1,-1,0,0};
        while(que.size()){
            auto t = que.front();
            que.pop();
            int x,y;
            for(int i = 0;i < 2;i++){
                for(int j = 0;j < 3;j++){
                    if(t[i][j] == 0){
                        x = i,y = j;
                    }
                }
            }
            for(int i = 0;i < 4;i++){
                int nx = x + dx[i],ny = y + dy[i];
                if(nx >= 0 && nx < 2 && ny >= 0 && ny < 3){
                    auto st = t;
                    swap(st[x][y],st[nx][ny]);
                    if(!dist.count(st)){
                        dist[st] = dist[t] + 1;
                        if(st == target) return dist[st];
                        que.push(st);
                    }
                }
            }
        } 
        return -1;
    }
};