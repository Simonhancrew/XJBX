#include <vector>
using namespace std;
/*
    回溯模板
    if(){
        do ...
        return
    }
    for(){
        do ....
        回溯
        pop_back+撤销改变
    }
*/
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        DFS(k,n,1);
        return result;
    }
private:
    vector<int> cur;
    vector<vector<int>> result;
    void DFS(int k,int sum,int index){
        if(k == 0 && sum == 0){
            result.push_back(cur);
            return;
        }
        if(k == 0 || sum<0){
            return;
        }
        for(int i = index;i<=9;i++){
            cur.push_back(i);
            DFS(k-1,sum-i,i+1);
            cur.pop_back();
        }
    }
};