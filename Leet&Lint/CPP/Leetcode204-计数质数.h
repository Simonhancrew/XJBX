//过不去
class Solution {
public:
    int countPrimes(int n) {
        if(n < 2) {
            return 0;
        }
        int ret = 0;
        bool odd;
        for(int i = 2;i < n;++i){
            odd = true;
            for(int j = 2;j < i;++j){
                if(i % j == 0){
                    odd = false;
                    break;
                }
            }
            if(odd) ret++;
        }
        return ret;
    }
};

//x是一个合数，他的因子y和x/y中较小的落在（2，sqrt(x)）中，所以，可以缩小查找的范围
class Solution {
public:
    bool isPrime(int n){
        if(n < 2){
            return false;
        }
        for(int i = 2;i * i <= n;++i){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
    int countPrimes(int n){
        int ret = 0;
        for(int i = 2;i<n;++i){
            if(isPrime(i)){
                ret++;
            }
        }
        return ret;
    }
};
//埃氏筛，一个数是质数，他的2x，3x...一定不再是质数
//开一个数组，去标记这些数
//从x*x开始标记，因为x之前，2x..之类的肯定被标记了
#include <vector>
class Solution {
public:
    int countPrimes(int n){
        using namespace std;
        vector<int> prime(n,1);
        int ret = 0;
        for(int i = 2;i < n;i++){
            if(prime[i]){
                ret++;
                if((long long) i * i < n){
                    for(int j = i * i;j < n;j+=i){
                        prime[j] = 0;
                    }
                }
            }
        }
        return ret;
    }
};

//线性筛
class Solution {
public:
    int countPrimes(int n) {
        using namespace std;
        vector<int> primes;
        vector<int> isPrime(n, 1);
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
            for (int j = 0; j < primes.size() && i * primes[j] < n; ++j) {
                isPrime[i * primes[j]] = 0;
                if (i % primes[j] == 0) {
                    break;
                }
            }
        }
        return primes.size();
    }
};