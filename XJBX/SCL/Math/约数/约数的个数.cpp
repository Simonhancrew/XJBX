#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int mod = 1e9 + 7;
//int范围内的数，约数最多的数有1500个左右
typedef long long LL;

int main(){
    int n;
    cin >> n;
    unordered_map<int,int> primes;
    while(n--){
        int a;
        cin >> a;
        //记录一下每个质因子的指数
        for(int i = 2;i <= a / i;i++){
            while(a % i == 0){
                a /= i;
                primes[i]++;
            }
        }
        if(a > 1) primes[a]++;
    }
    //1e9 * 1e9会爆int
    LL res = 1;
    for(auto prime:primes){
        //分解质因子的每个质因数可以选0次和他的指数次
        res = res * (prime.second + 1) % mod;
    }
    cout << res;
    return 0;
}