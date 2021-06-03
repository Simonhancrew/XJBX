#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

//前缀和的应用，把0变成-1，只要这一段前缀和相减得0就说明有相等得01出现次数

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>  mp;
        mp[0] = -1;
        int n = nums.size(),cnt = 0,ans = 0;
        int cur;
        for(int i = 0;i < n;i++){
            cur = nums[i] == 1?1:-1;
            cnt += cur;
            if(mp.count(cnt)){
                ans = max(ans,i - mp[cnt]);
            }else{
                mp[cnt] = i;
            }
        }
        return ans;
    }
};