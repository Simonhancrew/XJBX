// 一位质数和一位偶数有多少个？
// 每一位有多少种放法？

class Solution {
public:
    using ll = long long;
    const int MOD = 1e9 + 7;
    ll qmi(ll a,ll b){
        ll res = 1;
        while(b){
            if(b & 1) res  = res * a % MOD;
            a = (ll)a * a  % MOD;
            b >>= 1; 
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        return qmi(5,(n + 1)/2) *  qmi(4,n / 2) % MOD;
    }
};