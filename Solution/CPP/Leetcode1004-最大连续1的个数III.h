#include <vector>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int ans = 0;
        int n = A.size();
        int zeros = 0;
        int start = 0;
        for(int end = 0;end < n;end++){
            if(A[end] == 0){
                zeros++;
            }
            while(zeros > K){
                if(A[start++] == 0){
                    zeros--;
                }               
            }
            ans = max(ans,end - start + 1);
        }
        return ans;
    }
};