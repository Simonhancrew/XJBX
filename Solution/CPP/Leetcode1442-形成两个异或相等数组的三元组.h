#include <vector>
using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> presum(n + 1);
        presum[0] = 0;
        for(int i = 1;i <= n;i++){
            presum[i] = presum[i - 1] ^ arr[i - 1];
        }
        int res = 0;
        for(int i = 0;i < n;i++){
            for(int k = i + 1;k < n;k++){
                if(presum[i] == presum[k + 1]) res += k - i;
            }
        }
        return res;
    }
};