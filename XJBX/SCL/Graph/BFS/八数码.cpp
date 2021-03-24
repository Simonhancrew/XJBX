#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int bfs(string start){
    queue<string> q;
    unordered_map<string,int> d;
    string end = "12345678x";
    q.push(start);
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    d[start] = 0;
    while(q.size() > 0){
        auto t = q.front();
        q.pop();
        if(t == end) return d[t];
        int distance = d[t];
        //idex
        int k = t.find('x');
        //index 2 (x,y)
        int x = k / 3,y = k % 3;
        //4 direction up down left right
        for(int i = 0;i < 4;i ++){
            int newx = x + dx[i],newy = y + dy[i];
            //boarder limit
            if(newx >= 0 && newx < 3 && newy >= 0 && newy < 3){
                swap(t[k],t[newx * 3 + newy]);
                //undetected position
                if(!d.count(t)) {
                    d[t] = distance + 1;
                    //dont forget to push the state
                    q.push(t);
                }
                //还原现场
                swap(t[k],t[newx * 3 + newy]);
            }
            
        }
    }
    return -1;
}

int main(){
    string start;
    for(int i = 0;i < 9;i++){
        char cur;
        cin >> cur;
        start += cur;
    }
    cout << bfs(start) << endl;
    return 0;
}