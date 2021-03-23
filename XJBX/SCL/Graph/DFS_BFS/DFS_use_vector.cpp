#include <vector>
#include <iostream>

using namespace std;

void dfs(int idx,int end,vector<int> &use,vector<int> res){
    if(idx == end){
        for(int i = 0;i < end;i++){
            cout << res[i] << ' ';
        }
        cout << endl;
        return;
    }
    for(int i = 1;i <= end;i++){
        if(use[i] == 0){
            use[i] = 1;
            res.push_back(i);
            dfs(idx + 1,end,use,res);
            use[i] = 0;
            res.pop_back();
        }
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> use(n + 1,0);
    vector<int> res;
    dfs(0,n,use,res);
    return 0;
}