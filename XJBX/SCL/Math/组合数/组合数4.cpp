// #pragma GCC optimize(2)//手动氧气优化
#include <iostream>
#include <vector>

//从定义出发，直接求出组合数，不mod。这里需要使用高精度算法、
//高精度不要全部求，先分解质因数之后再去做高精度乘法
//c++能在1s算出来的复杂度大概在 1e8 左右

using namespace std;

const int N  = 5010;
int primes[N],cnt;
int sum[N];
bool st[N];

//线性筛
void get_primes(int n){
    for(int i = 2;i <= n;i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0;primes[j] <= n / i;j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

//拿到a中质因子p的指数
int get(int n,int p){
    int res = 0;
    while(n){
        res += n / p;
        n /= p;
    }
    return res;
}

//高精度乘法
vector<int> mul(vector<int> a,int b){
    vector<int> c;
    int t = 0;
    for(int i = 0;i < a.size();i++){
        t +=  a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while(t){
        c.push_back(t % 10);
        t /= 10;
    }
    while(c.size() > 1 && c.back() == 0) c.pop_back();
    return c ;
}

int main(){
    int a,b;
    cin >> a >> b;
    //对a分解质因数，求出a以内所有的质数
    get_primes(a);
    //拿到他们的指数
    for(int i = 0;i < cnt;i++){
        int p = primes[i];
        sum[i] = get(a,p)-get(b,p)-get(a - b,p);
    }
    vector<int> res;
    res.push_back(1);
    for(int i = 0;i < cnt;i++){
        for(int j = 0;j < sum[i];j++){
            res = mul(res,primes[i]);
        }
    }
    for(int i = res.size() - 1;i >= 0;i--) printf("%d",res[i]);
    return 0;
}