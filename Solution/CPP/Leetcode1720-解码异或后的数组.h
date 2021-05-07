#include <vector>

using namespace std;
//异或满足交换律和分配律
//从encoded[i] = arr[i] XOR arr[i+1] 可以两边同异或arr[i]推知 arr[i+1] = encoded[i] XOR arr[i].
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size() + 1;
        vector<int> res(n,0);
        res[0] = first;
        for(int i = 1;i < n;i++){
            res[i] = res[i - 1] ^ encoded[i - 1];
        }
        return res;
    }
};