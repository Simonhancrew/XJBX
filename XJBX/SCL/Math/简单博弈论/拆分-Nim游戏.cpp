#include <iostream>
#include <cstring>
#include <unordered_set>

/*

一个局面拆分成了两个局面，由SG函数理论，多个独立局面的SGSG值，等于这些局面SGSG值的异或和

*/
using namespace std;
const int N = 110;
int f[N];

int sg(int x){
    if(f[x] != -1) return f[x];

    unordered_set<int> S;
    for(int i = 0;i < x;i++){
        for(int j = 0;j <= i;j++){
            S.insert(sg(i) ^ sg(j));
        }
    }
    for(int i = 0;;i++){
        if(!S.count(i)){
            return f[x] = i;
        }
    }
}

int main(){
    int n;
    cin >> n;
    int res = 0;
    memset(f,-1,sizeof f);
    while(n--){
        int x;
        cin >> x;
        res ^= sg(x);
    }
    if(res) puts("Yes");
    else puts("No");
    return 0;
}