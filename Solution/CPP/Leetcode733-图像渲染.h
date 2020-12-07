#include<vector>
#include<queue>
using namespace std;
//广度优先搜索
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        const int dx[4] = {1,-1,0,0};
        const int dy[4] = {0,0,-1,1};
        int currcolor = image[sr][sc];
        if(currcolor == newColor) return image;
        queue<pair<int,int>> que;
        que.push(make_pair(sr,sc));
        image[sr][sc] = newColor;
        int n = image.size(),m = image[0].size();
        while(!que.empty()){
            int x = que.front().first,y = que.front().second;
            que.pop();
            for( int i = 0;i<4;i++){
                int ax = x+dx[i],ay = y+dy[i];
                if(ax >= 0 && ax < n && ay >= 0 && ay < m && image[ax][ay] == currcolor){
                    que.push(make_pair(ax,ay));
                    image[ax][ay] = newColor;
                }
            }
        }
        return image;
    }
};
//深度优先搜索
class Solution2{
public:
    const int dx[4] = {1,-1,0,0};
    const int dy[4] = {0,0,-1,1};
    void dfs(vector<vector<int>>& image, int sr, int sc,int color, int newColor){
        if(image[sr][sc] == color){
            image[sr][sc] = newColor;
            for(int i = 0;i<4;i++){
                int ax = sr + dx[i];
                int ay = sc + dy[i];
                if(ax >=0 && ax<image.size() && ay >= 0 && ay<image[0].size() && image[ax][ay] == color){
                    dfs(image,ax,ay,color,newColor);
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){
        if(image[sr][sc] == newColor){
            return image;
        }
        int color = image[sr][sc];
        dfs(image,sr,sc,color,newColor);
        return image;
    }
};