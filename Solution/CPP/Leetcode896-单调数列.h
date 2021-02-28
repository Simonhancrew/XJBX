#include <vector>
using namespace std;
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool inc = true,dec = true;
        int n = A.size();
        for(int i = 0;i < n - 1;i ++){
            if(A[i] > A[i + 1]){
                inc = false;
            }
            if(A[i] < A[i  + 1]){
                dec = false;
            }
        }
        return inc||dec;
    }
};