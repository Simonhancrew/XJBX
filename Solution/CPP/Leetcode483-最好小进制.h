#include <string>

using namespace std;

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