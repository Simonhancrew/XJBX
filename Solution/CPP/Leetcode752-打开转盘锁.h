#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        string start = "0000";
        if(target == start) return 0;
        unordered_set<string> lock;
        for(auto &s:deadends) lock.insert(s);
        if(lock.count(start)) return -1;
        unordered_map<string,int> dist;
        dist[start] = 0;
        queue<string> que;
        que.push(start);
        while(que.size()){
            auto t = que.front();
            que.pop();
            for(int i = 0;i < 4;i++){
                for(int j = -1;j < 2;j += 2){
                    auto state = t;
                    state[i] = (state[i] - '0' + j + 10) % 10 + '0';
                    if(!dist.count(state) && !lock.count(state)){
                        dist[state] = dist[t] + 1;
                        if(state == target) return dist[state];
                        que.push(state);
                    }
                }
            }
        }
        return -1;
    }
};