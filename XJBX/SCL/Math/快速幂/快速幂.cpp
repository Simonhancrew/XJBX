#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

//快速幂求解的是pow(a,k) mod p的问题
//把幂换成二进制加法表示，然后求指数变成乘法原理，乘法分配率，每个mod，相乘，再把结果mod
//注意数据大的时候要用long long 存数据

int qmi(int a,int k,int p){
    int res = 1;
    while(k){
        if(k & 1) res = (LL)res * a % p;
        k >>= 1;
        a = (LL)a * a % p;
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int a,k,p;
        scanf("%d%d%d",&a,&k,&p);
        printf("%d",qmi(a,k,p));
    }
    return 0;
}