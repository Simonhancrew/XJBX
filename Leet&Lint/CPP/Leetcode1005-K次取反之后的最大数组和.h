#include <vector>
#include <algorithm>
using namespace std;
//首先把负的变成正的，优先变绝对值大的
//然后如果K还有的话，就等价于在全正数的序列中改变
//K = 奇数时必须变一位，就变绝对值最小的，偶数就不变
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(),A.end(),[](int lhs,int rhs){
            return abs(lhs) > abs(rhs);
        });
        int n = A.size();
        for(int i = 0;i < n;++i){
            if(A[i] < 0 && K > 0){
                A[i] = -A[i];
                K--;
            }
        }
        if(K % 2 == 1){
            A[n - 1] = -A[n - 1];
        }
        int ret = 0;
        for(auto& a:A){
            ret += a;
        }
        return ret;
    }
};