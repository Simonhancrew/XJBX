#include <iostream>

using namespace std;
using LL = long long;

//卡特兰数求解,画格子，N*N。向上0，向右1.


const int mod = 1e9 + 7;

int qmi(int a,int k){
    int res = 1;
    while(k){
        if(k & 1) res = (LL) res * a % mod;
        k >>= 1;
        a = (LL) a * a % mod;
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    int a = 2 * n, b = n;
    int res = 1;
    for(int i = a;i > a - b;i--) res = (LL)res * i % mod;
    for(int i = 1;i <= b;i++) res = (LL)res * qmi(i,mod - 2) % mod;
    res = (LL) res * qmi(n+1,mod - 2) % mod;
    cout << res << endl;
    return 0;
}

