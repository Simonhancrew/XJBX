#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(),n = matrix[0].size();
        int i = 0,j = n-1;
        //O(m+n),所见搜索的范围
        while(i < m && j >= 0){
            if(matrix[i][j] < target) ++i;
            else if(matrix[i][j] > target) --j;
            else return true;
        }
        return false;
    }
};