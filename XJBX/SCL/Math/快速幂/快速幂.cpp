#include <iostream>

//把幂换成二进制加法表示，然后求指数变成乘法原理，乘法分配率，每个mod，相乘，再把结果mod
//注意数据大的时候要用long long 存数据

using namespace std;

typedef long long LL;
 
LL qmi(int a,int k ,int p){
    int res = 1;
    while(k){
        //乘的过程中可能爆int，所以需要特判
        if(k & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int a,p;
        cin >> a >> p;
        LL t = qmi(a,p-2,p);
        //a和p不互质的话，没有结果
        if (a % p == 0) puts("impossible");
        else cout << t << endl;
    }
    return 0;
}