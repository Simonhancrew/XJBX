#include <vector>
using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(matrix[i][j] > target){
                    return false;
                }else if(matrix[i][j] == target){
                    return true;
                }else{
                    continue;
                }
            }
        }
        return false;
    }
};

//用二分重新做一下
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(),m = matrix[0].size();
        int l = 0,r = m * n - 1;
        while(l < r){
            int mid = (r + l) >> 1;
            if(matrix[mid / m][mid % m] >= target) r = mid;
            else l = mid + 1;
        }
        return matrix[l / m][l % m] == target;
    }
};