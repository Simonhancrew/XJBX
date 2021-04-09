#include <iostream>
#include <cstring>
#include <algorithm>

//奇数级台阶石子异或和不变

int main(){
    int n;
    scanf("%d", &n);
    int res = 0;
    for(int i = 1;i <= n;i++){
        int a;
        scanf("%d",&a);
        if(i % 2) res ^=  a;
    }
    if(res) puts("Yes");
    else puts("No");
    return 0;
}