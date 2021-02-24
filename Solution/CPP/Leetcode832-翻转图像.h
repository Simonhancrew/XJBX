#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int m = A.size(),n = A[0].size();
        for(int i = 0;i < m;i++){
            int start = 0,end = n -1;
            while(start < end){
                swap(A[i][start],A[i][end]);
                start++;
                end--;
            }
            for(int j = 0;j < n;j++){
                A[i][j] = 1 - A[i][j];
            }
        }
        return A;
    }
};