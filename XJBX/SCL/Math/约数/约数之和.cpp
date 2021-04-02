#include <iostream>
#include <unordered_map>

typedef long long LL;

//求所有约数之和,先分解质因数，然后对于每个质因数选0-指数次
//最后乘法原理（拆解括号之后分配律），既是所有的约数之和

using namespace std;

const int mod = 1e9 + 7;

int main(){
    int n;
    cin >> n;
    unordered_map<int,int> primes;
    while(n--){
        int x;
        cin >> x;
        for(int i = 2;i <= x / i;i++){
            while(x % i == 0){
                x /= i;
                primes[i]++;
            }
        }
        if(x > 1) primes[x] ++;
    }
    
    LL res = 1;
    
    for(auto prime:primes){
        //p是底数，a是指数
        int p = prime.first,a = prime.second;
        LL t = 1;
        //p^0 + p^1 + p^2 + ... + p^a
        while(a--) t = (t * p + 1) % mod;
        res = res * t % mod;
    }
    cout << res;
    return 0;
}

