#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        vector<int> res;
        int n = matrix.size(),m = matrix[0].size();
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(i - 1 >= 0) matrix[i][j] ^= matrix[i- 1][j];
                if(j - 1 >= 0) matrix[i][j] ^= matrix[i][j - 1];
                if(i - 1 >= 0 && j - 1 >= 0) matrix[i][j] ^= matrix[i - 1][j - 1];
                res.push_back(matrix[i][j]); 
            }
        }
        sort(res.begin(),res.end(),greater<int>());
        return res[k - 1];
    }
};