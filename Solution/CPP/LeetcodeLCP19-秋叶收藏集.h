#include <string>
#include <vector>
#include <climits>
//动态规划三部曲
//1找到最后一步转移状态
//2如何开动态规划的数组（类似于这种向前推进加多状态的，一般都是二维数组）
//3扣出边界和无效状态
//4子问题最优化了没有？
//5可不可以用滚动数组优化？
using namespace std;
//求解具体数值->动态规划
//最后一部的状态->最后一个节点调整为红色，加上上一个节点调整为相应状态的次数
//开数组，f[树叶size][3个状态]，到当前节点的时候，是状态i的调整次数
//每个状态最少一个节点，没用的值设为INT_MAX(f[i][j] ->  i<j)
//扣节点的转移状态，令其子问题最优。
class Solution {
public:
    int minimumOperations(string leaves) {
        int size = leaves.size();
        vector<vector<int>> f(size,vector<int> (3));
        f[0][0] = (leaves[0] == 'y');
        f[0][1] = INT_MAX;
        f[0][2] = INT_MAX;
        f[1][2] = INT_MAX;
        for(int i = 1;i<size;++i){
            int isRed = (leaves[i] == 'r');
            int isYellow = (leaves[i] == 'y');
            f[i][0] = f[i-1][0]+isYellow;
            f[i][1] = min(f[i-1][0],f[i-1][1])+isRed;
            if(i>=2){
                f[i][2] = min(f[i-1][1],f[i-1][2])+isYellow;
            }
        }
        return f[size-1][2];
    }
};