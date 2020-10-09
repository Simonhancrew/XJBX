#include <vector>
using namespace std;
//矩阵分圈处理，注意循环不变量
//一圈中，上行左闭右开，右列上闭下开，下行右闭左开，左列下闭上开
//奇数的时候处理不到中心，所以要多判断一次，赋值中心位置
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));//构建nn矩阵
        int loop = n/2;//需要处理的圈数
        int startx = 0,starty = 0;//初始的index
        int count = 1;//数字从1开始
        int mid = n/2;//奇数中间还要处理一次
        int offset = 1;//处理的边长偏移，因为开闭区间的问题，不处理矩阵的整行和整列
        //分圈处理
        while(loop--){
            int i = startx;
            int j = starty;

            //一圈中的四个边的处理
            //上行从左到右
            for(;j<starty+n-offset;j++){
                res[startx][j] = count++;
            }
            //右列从上到下
            for(;i<startx+n-offset;i++){
                res[i][j] =count++; 
            }
            //下行从右到左
            for(;j>starty;j--){
                res[i][j] = count++;
            }
            //左列从下到上
            for(;i>startx;i--){
                res[i][starty] = count++;
            }
            //更新下一圈的初始位置
            startx++,starty++;
            //offset也要更新,左右都有边，减2
            offset += 2;
        }
        //奇数中心处理不到
        if(n%2 != 0){
            res[mid][mid] = count;
        }
        return res;
    }
};