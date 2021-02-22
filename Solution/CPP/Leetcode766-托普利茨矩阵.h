#include <vector>
using namespace std;
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(),n = matrix[0].size();
        for(int start = 1;start < n;start++){
            if(check(matrix,m-1,start) == false){
                return false;
            }
        } 
        for(int start = m-2;start > 0;start--){
            if(!check(matrix,start,n-1)){
                return false;
            }
        }
        return true;
    }
    bool check(vector<vector<int>> &matrix,int row,int col){
        int curr = row - 1;
        int curc = col - 1;
        if(curr >= 0 && curc >= 0){
            if(matrix[row][col] == matrix[curr][curc]){
                return check(matrix,curr,curc);
            }else{
                return false;
            }
        }
        return true;
    }
};
