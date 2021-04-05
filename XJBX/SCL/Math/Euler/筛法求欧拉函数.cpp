#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1e6 + 10;

int primes[N],cnt;
int phi[N];
bool st[N];

//因为可能溢出，所以要开long long
LL euler(int n){
    phi[1] = 1;//按照定义约定一下
    for(int i = 2;i <= n;i++){
        if (!st[i]){
            primes[cnt ++ ] = i;
            //一个数是质数的话,根据欧拉公式,他的欧拉函数就是i - 1
            phi[i] = i - 1;
        }
        for (int j = 0;primes[j] <= n / i;j++){
            st[primes[j] * i] = true;
            //i能够能够被pj整除的时候，合数，已经被标记了，phi[i]、已经求出了
            if (i % primes[j] == 0) {
                //phi[i] * pj的质因子没有改变
                phi[i * primes[j]] = primes[j] * phi[i];
                break;
            }
            //i不能被pj整除的时候记录一下i * pj的欧拉函数，根据定义，phi[i]的值因子不包含pj
            phi[i * primes[j]] = phi[i] * (primes[j] - 1);
        }
    }
    LL res = 0;
    for(int i = 1;i <= n;i++){
        res += phi[i];
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    cout << euler(n) << endl;
    return 0;
}
