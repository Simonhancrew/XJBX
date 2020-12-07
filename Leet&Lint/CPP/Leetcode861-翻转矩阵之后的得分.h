#include <vector>
using namespace std;
//贪心的方法，把最左一列通过行变化先全部变1
//之后对每一列，如果1的数大于0，不变，反之就变
//实际的过程中，不需要变换矩阵的值，只要统计每个位置的贡献值就可以了
//每一列统计完之后选出贡献更大的方式，变或者不变
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size(),n = A[0].size();
        int ret = m * (1 << (n - 1));//最左边的一列的贡献
        //从左到右的每一列，每一列的贡献都是1<<n - 1 - i
        int cur = 0;
        for(int i = 1;i < n;++i){
            cur = 0;
            //每一行
            for(int j = 0;j < m;++j){
                if(A[j][0] == 1){
                    cur += A[j][i];
                }else{
                    //此时行首为0，需要变换一次，此时实际贡献为1 - A[j][i]
                    cur += 1 - A[j][i]; 
                }
            }
            //那种贡献更大
            cur = max(cur,m - cur);
            ret += cur * (1 << (n - i - 1));
        }
        return ret;
    }
};