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
        //如果是质数就记录下来
        if(!st[i]) primes[cnt++] = i;
        //从大到小枚举质数，pj一定小于i的质因子
        for(int j = 0;primes[j] <= n / i;j++){
            //每一次把i和质数的乘筛掉
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