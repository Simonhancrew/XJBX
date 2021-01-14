#include <vector>
using namespace std;
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int n = A.size();
        vector<bool> res(n,false);
        int cur = 0;
        for(int i = 0;i < n;++i){
            cur <<= 1;
            if(cur >= 10){
                cur -= 10;
            }
            int num = A[i];
            cur += num;
            if(cur % 5 == 0){
                res[i] = true;
            }
        }
        return res;
    }
};