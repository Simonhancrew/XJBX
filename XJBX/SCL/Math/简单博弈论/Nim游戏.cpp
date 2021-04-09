#include <iostream>

//公平游戏，步骤可见。
//先手下棋之后，下一个状态是必败的，则说明先手是必胜的

using namespace std;

int main(){
    int n;
    cin >> n;
    int res;
    while(n--){
        int a;
        cin >> a;
        res ^= a;
    }
    //异或一起是0，先手必败
    if(res == 0) puts("No");
    else puts("Yes");
    return 0;
}