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

n只会被他的最小质因子筛掉，这是线性筛的核心
只有质数的倍数才会被筛掉
1-n中有n/ln(n)个质数

*/
void get_prime_linear(int n){
    for(int i = 2;i <= n;i++){
        //如果是质数就记录下来
        if(!st[i]) primes[cnt++] = i;
        //从大到小枚举质数，pj一定小于i的质因子
        //保证primes[j]一定是最小的
        for(int j = 0;primes[j] <= n / i;j++){//pj * i <= n，pj * i小于n才有意义
            //每一次把i和质数的乘筛掉，此时pj不是i的质因子，pj一定小于所有i的值因子（从小到大枚举的质因子）
            st[primes[j] * i] = true;
            //primes[j]一定是i的最小质因子，因为是从小到大枚举每个质数的
            if(i % primes[j] == 0) break; 
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