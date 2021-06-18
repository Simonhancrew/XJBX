#include <string>

using namespace std;

// 根据题目的范围，[3,1e18],首先确定n是可以爆int的（1e9以内）
// 之后我们确定一下位数，t = log2(n) + 1是最大的长度，进制最小是2进制
// 显然t越长，k越小，所以可以倒着枚举
// 然后可以根据二项公式推出来一个范围k = int(pow(n,1 / (t - 1)))

class Solution {
public:
    string smallestGoodBase(string n) {
        using ll = long long;
        ll N = stoll(n);
        for(int t = log2(N) + 1;t >= 3;t--){
            ll k = pow(N, 1.0 / (t - 1));
            ll r = 0;
            for(int i = 0;i < t;i++) r = r * k + 1;
            if(N == r) return to_string(k);
        }
        return to_string(N - 1);
    }
};