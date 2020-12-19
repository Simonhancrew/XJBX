#include <vector>
using namespace std;
//矩阵分圈的思想
//首先找到最外圈四个顶点，分布的处理每一条边
//首先交换四个顶点，然后将处理顶点所在的边，将顶点在边上推进一步（offset）
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int tr = 0;
        int dr = matrix.size() - 1;
        //中心点不用处理
        //处理圈
        while(tr < dr){
            rotatesircle(matrix,tr++,dr--);
        }
    }
private:
    void rotatesircle(vector<vector<int>> &matrix ,int tr,int dr){
        int offset = dr - tr;
        int tmp = 0;
        for(int i = 0;i < offset;++i){
            tmp = matrix[tr][tr + i];
            matrix[tr][tr + i] = matrix[dr - i][tr];
            matrix[dr - i][tr] = matrix[dr][dr - i];
            matrix[dr][dr - i] = matrix[tr + i][dr];
            matrix[tr + i][dr] = tmp;
        }
    } 
};