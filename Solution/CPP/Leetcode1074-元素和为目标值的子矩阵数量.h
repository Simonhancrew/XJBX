#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 思路就是枚举上下行的边界，然后做这个区间的列的一维维前缀和
    // 然后就可以转化成一维，等价于在这个一维的区间中，找到区间和为k的个数
    // pre[i] - prex = k,求之前前缀和为prex的区间有多少个
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(),m = matrix[0].size();
        int ans = 0;
        for(int i = 0;i < n;i++){
            vector<int> presum(m);
            for(int j = i;j < n;j++){
                for(int k = 0;k < m;k++){
                    presum[k] += matrix[j][k];
                }
                ans += count(presum,target);
            }
        }        
        return ans;
    }

    int count(vector<int> &presum,int target){
        unordered_map<int,int> mp;
        mp[0] = 1;
        int res = 0,cur = 0;
        for(int i = 0;i < presum.size();i++){
            cur += presum[i];
            if(mp.count(cur - target)){
                res += mp[cur - target];
            }
            mp[cur]++;
        }
        return res;
    }
};