#include <vector>
using namespace std;
//贪心的策略
//先从左到右，确定左孩子比右孩子小的情况下，右孩子拿到了更多的糖->+1
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> res(n,1);
        //先从左到右，保证右边大于左边的时候是正确的糖果分发
        for(int i = 1;i < n;++i){
            if(ratings[i] > ratings[i - 1]){
                res[i] = res[i - 1] + 1;
            }
        }
        //然后从右到左，确定右边小于左边的时候分发的糖果正确
        for(int i = n - 2;i >= 0;--i){
            if(ratings[i] > ratings[i + 1]){
                res[i] = max(res[i],res[i + 1] + 1);
            }
        }
        int ans = 0;
        for(int every:res){
            ans += every;
        }
        return ans;
    }
};