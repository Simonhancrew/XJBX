#include <vector>
using namespace std;
//同之前的动态规划一样
//只不过考虑特殊情况
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid.at(0).size();
        vector <int> f(m);

        f[0] = (obstacleGrid[0][0] == 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    f[j] = 0;
                    continue;
                }
                if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0) {
                    f[j] += f[j - 1];
                }
            }
        }

        return f.back();
    }
};

//第一行或者第一列也是可能有1的
//所以有1的话后续的处理就是将dp数组第一行（列）剩下的值全部设置为0
#include <algorithm>
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0][0] == 1){
            return 0;
        }
        int m =  obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> arr(m,vector<int>(n,0));
        //第0行若有障碍物则同行后面为0，否则为1
        for(int i =0 ;i< n ; i++){
            if(obstacleGrid[0][i] == 0)
                arr[0][i] = 1;
            if(obstacleGrid[0][i] == 1){
                while(i<n){
                    arr[0][i] = 0;
                    i++;
                }
            }
        }
        //第0列若有障碍物则同列后面为0，否则为1
        for(int i =0 ;i< m ; i++){
            if(obstacleGrid[i][0] == 0)
                arr[i][0] = 1;
            if(obstacleGrid[i][0] == 1){
                while(i<m){
                    arr[i][0] = 0;
                    i++;
                }
            }
        }
        //第0行第0列已经赋值，从[1][1]开始赋值就好
        for (int i = 1; i < m; i++){
            for(int j =1; j < n; j++){
                if(obstacleGrid[i][j] == 1){
                    arr[i][j] = 0;
                }
                else{
                    arr[i][j] = arr[i-1][j] + arr[i][j-1];
                }
            }
        }
        return arr[m-1][n-1];
    }
};