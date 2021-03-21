#include <vector>
using namespace std;
//开两个标记数组
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(),n = matrix[0].size();
        vector<int> row(m);
        vector<int> col(n);
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(!matrix[i][j]){
                    row[i] =  col[j] = 1;
                }
            }
        }
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(row[i] || col[j]){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

//开两个标记变量
//标记0行0列需不需要变，之后从1开始遍历
class Solution{
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int col = 1,row = 1;
        for(int i = 0;i < n;i++){
            if(!matrix[0][i]){
                row = 0;
            }
        }

        for(int i = 0;i < m;i++){
            if(!matrix[i][0]){
                col = 0;
            }
        }
        
        for(int i = 1;i < m;i++){
            for(int j = 1;j < n;j++){
                if(!matrix[i][j]){
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1;i < m;i++){
            for(int j = 1;j < n;j++){
                if(!matrix[0][j] || !matrix[i][0]){
                    matrix[i][j] = 0;
                }
            }
        }
        if(!col){
            for(int i = 0;i < m;i++){
                matrix[i][0] = 0;
            }
        }
        if(!row){
            for(int i = 0;i < n;i++){
                matrix[0][i] = 0;
            }
        }
    }
};