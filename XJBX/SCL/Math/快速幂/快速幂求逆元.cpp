#include <iostream>

//给定a和p，求a mod p 的乘法逆元，设计费马小定理，对式子进行转换之后就是一个快速幂
//a 和 p 互质的时候就是求 a ^ (p-2)的值

using namespace std;

typedef long long LL;
 
LL qmi(int a,int k ,int p){
    int res = 1;
    while(k){
        if(k & 1) res = res * a % p;
        a = (LL)a * a % p;
        p >> 1;
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int a,p;
        cin >> a >> p;
        LL t = qmi(a,p-2,1);
        if (a % p == 0) puts("impossible");
        else cout << t;
    }
    return 0;
}