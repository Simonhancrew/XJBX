#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int N = 1e6+10;

int son[N][26],idx;
int cnt[N];

void insert(string word){
    int p = 0;
    int n = word.size();
    for(int i = 0;i < n;i++){
        int u = word[i] - 'a';
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}
int query(string word){
    int p = 0;
    int n = word.size();
    int res = 0;
    for(int i = 0;i < n;i++){
        int u = word[i] - 'a';
        if(!son[p][u]) break;
        p = son[p][u];
        res += cnt[p];
    }
    return res;
}

int main(){
    int n,m;
    cin >> n >> m;
    while(n--){
        string t;
        cin >> t;
        insert(t);
    }
    while(m--){
        string t;
        cin >> t;
        int ans = query(t);
        cout << ans << endl;
    }
    return 0;
}