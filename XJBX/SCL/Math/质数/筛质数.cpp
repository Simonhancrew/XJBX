#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int primes[N],cnt;
bool st[N];


void get_prime(int n){
    for(int i = 2;i <= n;i++){
        if(st[i])  continue;
        primes[cnt++] = i;
        //把所有质数的2倍以上的数全部标记位合数
        for(int j = i + i;j  <= n; j += i){
            st[j] = true;
        }
    } 
}

//线性筛法
/*
n只会被他的最小质因子筛掉


*/
void get_prime_linear(int n){
    for(int i = 2;i <= n;i++){
        if(!st[i]) primes[cnt++] = i;
        //
        for(int j = 0;primes[j] <= n;j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break; //primes[j]一定是i的最小质因子
        }
    }
 
}

int main(){
    int n;
    cin >> n;
    get_prime(n);
    cout << cnt << endl;
    return 0;
}