#include <iostream>

//引入裴蜀定理，任意正整数a,b,一定存在正整数x,y使得ax + by = gcd(a,b)

using namespace std;

int exgcd(int a,int b,int &x,int &y){
    if(!b){
        x = 1,y = 0;
        return a;
    }
    //推到过程就是拆分a % b
    //翻转有利于后续计算，递归结束后x,y符合条件
    int d = exgcd(b,a % b,y,x);
    //a % b = a - (a/b) * b 下取整 
    //组合之后拿到a和b的系数，a的系数是不改变的
    y -= a / b * x;
    return d;
}

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int a,b,x,y;
        scanf("%d%d",&a,&b);  
        exgcd(a,b,x,y);
        printf("%d %d\n",x,y);
    }
    return 0;
}