#include <vector>
#include <numeric>
using namespace std;
//从头尾拿k个数，最后的n-k一定时连续的
//滑动窗口找到这个最小值        
//滑动窗口求最值类型
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int windowsize = n - k;
        int sum = 0;
        for(int i = 0;i < windowsize;i++){
            sum += cardPoints[i];
        }
        int minsum = sum;
        for(int i = windowsize;i < n;i++){
            sum += (cardPoints[i] - cardPoints[i - windowsize]);
            minsum = min(minsum,sum);
        }
        int ans = accumulate(cardPoints.begin(),cardPoints.end(),0) - minsum;
        return ans;
    }
};