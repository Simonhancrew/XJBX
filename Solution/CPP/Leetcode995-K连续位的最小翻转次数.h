#include <vector>
using namespace std;
//差分数组的思想,区间改变，只处理前后的数就可以了
class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size();
        vector<int> dif(n+1);
        int ans = 0,cnt = 0;
        for(int i = 0;i < n;i++){
            //累加差分数组，得到当前反转的次数
            cnt += dif[i];
            //如果当前位置是0，肯定要反转的
            if((A[i] + cnt) % 2 == 0){
                //当前位置不够反转直接退出
                if(i + K > n){
                    return -1;
                }
                //反转次数改变
                ans++;
                cnt++;
                //差分数组末尾改变
                dif[i+K]--;
            }
        }
        return ans;
    }
};