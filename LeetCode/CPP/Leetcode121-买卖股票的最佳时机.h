#include <vector>
using namespace std;
//维护一个遍历到的最小值，一个最大卖出值
//不断去更新就可以了
class Solution {
public:
    int maxProfit(vector<int> &prices){
        int maxProfit = 0;
        int n = prices.size();
        if(n < 2){
            return 0;
        }
        int curLow = prices[0];
        for(int i = 1;i < n;++i){
            if(curLow > prices[i]){
                curLow = prices[i];
            }
            if(prices[i] > curLow && prices[i] - curLow > maxProfit){
                maxProfit = prices[i] - curLow;
            }
        }
        return maxProfit;
    }
};