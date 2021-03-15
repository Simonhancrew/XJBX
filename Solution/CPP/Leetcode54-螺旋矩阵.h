#include <vector>
using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        int top = 0,left = 0,right = n - 1,down = m - 1;
        while(top <= down && left <= right){
            for(int col = left;col <= right;col++){
                res.push_back(matrix[top][col]);
            }
            for(int row = top+1;row <= down;row++){
                res.push_back(matrix[row][right]);
            }

            if (left < right && top < down){
                for(int col = right - 1;col > left;col--){
                    res.push_back(matrix[down][col]);
                }
                for(int row = down;row > top;row--){
                    res.push_back(matrix[row][left]);
                }
            }
            top++,left++,down--,right--;
        }        
        return res;
    }
};