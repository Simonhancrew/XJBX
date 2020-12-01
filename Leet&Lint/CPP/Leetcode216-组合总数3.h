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

//重新理解回溯，一个k层，n宽的搜索树
class Solution {
public: 
    vector<vector<int>> combinationSum3(int k, int n){
        backtrack(n,k,0,1);
        return res;
    }
private:
    vector<int> path;
    vector<vector<int>> res;
    void backtrack(int target,int k,int sum,int index){
        //剪枝，值大于target就没必要继续
        if(sum > target){
            return;
        }
        //符合情况的push
        if(path.size() == k){
            if(sum == target) res.push_back(path);
            return;
        }
        //先本层的处理，先宽度
        for(int i = index;i<=9;++i){
            sum += i;
            path.push_back(i);
            //后深度k
            backtrack(target,k,sum,i+1);
            //回溯
            sum -= i;
            path.pop_back();
        }
    }
};