#include <iostream>

using namespace std;


//lowbit实现计数二进制中的1
/*
原
反
补 反码 + 1
求n的第k位数: n >> k & 1
求n的最后一位1: lowbit(n) = n & -n 
lobit利用补码和源码的性质，得到最后一位1的位置
比如，x = 1010000 
x & -x = 10000 
*/

const int N = 1e5 + 10;

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        int res,x;
        res = 0;
        scanf("%d",&x);
        while(x) x -= (x&(-x)),res++;
        printf("%d ",res);
    }
    return 0;
}