#include <iostream>


//利用扩展欧几里得算法去求解线性同余方程
using LL = long long;

using namespace std;

int exgcd(int a,int b,int &x,int &y){
    if(!b){
        x = 1,y = 0;
        return a;
    }
    int d = exgcd(b,a % b,y,x);
    y -= a / b * x;
    return d;
}

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int a,b,m;
        scanf("%d%d%d",&a,&b,&m);
        //等式变化一下，等价于exgcd
        int x,y;
        int d = exgcd(a,m,x,y);
        if(b % d) puts("impossible");
        //同时扩大 b / d
        else printf("%d\n",(LL) x * (b /d) % m);
    }

    return 0;
}