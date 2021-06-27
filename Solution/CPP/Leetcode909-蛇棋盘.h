#define x first
#define y second

class Solution {
public:
    typedef pair<int,int> PII;
    vector<vector<int>> id;
    vector<PII> cor;
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(),m = board[0].size();
        id = vector<vector<int>>(n,vector<int>(m,0));
        cor = vector<PII>(n * m + 1);
        for(int i = n - 1, s = 0, k = 1;i >= 0;i--,s++){
            if(s % 2 == 0){
                for(int j = 0;j < m;j++,k++){
                    id[i][j] = k;
                    cor[k] = {i,j};
                }
            }else{
                for(int j = m - 1;j >= 0;j--,k++){
                    id[i][j] = k;
                    cor[k] = {i,j};
                }
            }
        }
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        queue<PII> que;
        que.push({n - 1,0});
        dist[n - 1][0] = 0;
        while(que.size()){
            auto t = que.front();
            que.pop();
            int k = id[t.x][t.y];
            if(k == n * m) return dist[t.x][t.y];
            for(int i = k + 1;i <= k + 6 && i <= n * m;i++){
                int f = cor[i].x,s = cor[i].y;
                if(board[f][s] == -1){
                    if(dist[f][s] > dist[t.x][t.y] + 1){
                        dist[f][s] = dist[t.x][t.y] + 1;
                        que.push({f,s});
                    }
                }else{
                    int e = board[f][s];
                    f = cor[e].x,s = cor[e].y;
                    if(dist[f][s] > dist[t.x][t.y] + 1){
                        dist[f][s] = dist[t.x][t.y] + 1;
                        que.push({f,s});
                    }
                }
            }
        }   
        return -1;
    }
};