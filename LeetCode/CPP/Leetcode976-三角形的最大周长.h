#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(),A.end());
        int len = A.size();
        for(int i = len - 1;i >= 2;--i){
            if(A[i - 1] + A[i - 2] > A[i]){
                return A[i] + A[i-1] + A[i-2];
            }
        }
        return 0;
    }
};