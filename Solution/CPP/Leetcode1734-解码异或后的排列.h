#include <vector>
using namespace std;
//一般这种都要先求出一个原数组中的数。这里刚好告知了原来数组是那些数，且有规律可循，可以先算出最后一个原数组的数
class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1;
        vector<int> ans(n,0);
        int x = 0;
        for(int i = 1;i <= n;i++){
            x ^= i;
        }
        int cur = 0;
        for(int i = 0;i < n - 1;i += 2){
            cur ^= encoded[i];
        }
        int last = x ^ cur;
        ans[n - 1] = last;
        for(int i = n - 2;i >= 0;i--){
            ans[i] = ans[i + 1] ^ encoded[i];
        }
        return ans;
    }
};