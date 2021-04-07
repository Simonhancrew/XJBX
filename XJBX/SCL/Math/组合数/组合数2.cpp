#include <iostream>

//处理出来阶乘，然后利用乘法逆元去运算

using namespace std;
using LL = long long;

const int N = 1e5 + 10,mod = 1e9 + 7;
int fact[N],infact[N];

//快速幂就是把幂变成二进制和，提前处理出来a的1，2，4，logk次方，然后去处理幂上的1位置
//幂的二进制上是0的就不处理
int qmi(int a,int k,int p){
    int res = 1;
    while(k){
        if(k & 1) res = (LL) res * a % p;
        k >>= 1;
        a = (LL)a * a % p;
    }
    return res;
}

int main(){
    fact[0] = 1,infact[0] = 1;
    //分子和分母分别mod再除与原来是不一致的
    //变化成乘以乘法逆元
    for(int i = 1;i < N;i++){
        fact[i] = (LL)fact[i - 1] * i % mod;
        infact[i] = (LL)infact[i - 1] * qmi(i,mod - 2,mod) % mod;
    }
    int n;
    cin >> n;
    while(n --){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",(LL)fact[a] * infact[b] % mod * infact[a - b] % mod);
    }
    return 0;
}