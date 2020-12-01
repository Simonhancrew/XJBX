#include <vector>
using namespace std;
//和位相关的动态规划一般用值作为状态
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num+1,0);
        //dp[0] = 0;
        for(int i = 1;i <= num;++i){
            //去掉最后一位的话，他有多少个1？
            //最后一位是多少？
            //形成状态转移方程
            result[i] = result[i >> 1] + (i % 2);
        }
        return result;
    }
};