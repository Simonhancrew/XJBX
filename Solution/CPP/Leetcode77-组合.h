#include <vector>
using namespace std;
//n个数,k个一组
/*
    组合模板
    vector<int> temp;
    void dfs(int cur, int n) {
        if (cur == n + 1) {
            // 记录答案
            // ...
            return;
        }
    //考虑选择当前位置
    temp.push_back(cur);
    dfs(cur + 1, n, k);
    temp.pop_back();
    // 考虑不选择当前位置
  
*/
class Solution {
public:
    vector<int> temp;
    vector<vector<int>> result;

    void dfs(int cur, int n, int k) {
        // 剪枝：temp 长度加上区间 [cur, n] 的长度小于 k，不可能构造出长度为 k 的 temp
        if (temp.size() + (n - cur + 1) < k) {
            return;
        }
        // 记录合法的答案
        if (temp.size() == k) {
            result.push_back(temp);
            return;
        }
        // 考虑选择当前位置
        temp.push_back(cur);
        dfs(cur + 1, n, k);
        temp.pop_back();
        // 考虑不选择当前位置
        dfs(cur + 1, n, k);
    }

    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return result;
    }
};

//更深层的理解一下回溯，其实就是一个暴力法,其实就是一个树形的深搜，横向和纵向都有选和不选
//横向深搜和纵向深搜。少用一个系统栈的递归减少空间
class Solution {
public: 
    vector<int> temp;
    vector<vector<int>> result;
    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return result;
    }
private:
    void dfs(int cur,int n,int k){
        if (temp.size() + (n - cur + 1) < k) {
            return;
        }
        // 记录合法的答案
        if (temp.size() == k) {
            result.push_back(temp);
            return;
        }
        for(int i = cur;i <= n;++i){
            temp.push_back(i);
            dfs(i+1,n,k);
            temp.pop_back();
        }
    }
};