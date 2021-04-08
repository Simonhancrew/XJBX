#include <iostream>

//问的数据不多，但是数据的范围巨大，暴大
//mod的数不太大的时候，就可以考虑卢卡斯定理
//C(a,b)(lucas)≡C(a/p,b/p)(lucas) * C(a mod p,b mod p)(mod p)

using namespace std;
using LL = long long;

int p;

//乘法逆元，记住1e9 * 1e9要考虑爆int的问题
int qmi(int a,int k){
    int res = 1;
    while(k){
        if(k & 1) res = (LL)res * a % p;
        a = (LL) a * a % p;
        k >>= 1;
    }
    return res;
}

//定义出发求组和
int C(int a,int b){
    if(b > a) return 0;
    int res = 1;
    for(int i = 1,j = a;i <= b;i++,j--){
        res = (LL)res * j % p;
        res = (LL)res * qmi(i,p-2) % p; 
    }
    return res;
}

//公式卢卡斯，小于p停止递归
int lucas(LL a,LL b){
    if(a < p && b < p) return C(a,b);
    return (LL)C(a % p,b % p) * lucas(a / p,b / p) % p;
}


int main(){
    int n;
    cin >> n;
    while(n--){
        LL a,b;
        cin >> a >> b >> p;
        cout << lucas(a,b) << endl;
    }
    return 0;
}