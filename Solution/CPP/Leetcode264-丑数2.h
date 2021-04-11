//动态规划
#include <vector>
#include <cmath>
using namespace std;
//每一个丑数都可以从前面的丑数乘235推过来，尝试动态规划
//下一个丑数选择乘积最小的
class Solution {
public:
    int nthUglyNumber(int n) {
        //一个丑数乘2，3，5之后，就没有资格再乘了，所以需要将资格指针推进
        //只有p2,p3,p5指向的位置才有资格乘 2，3，5
        int p2 = 0,p3 = 0,p5 =0;
        vector<int> dp(n);
        dp[0] = 1;
        for(int i =1;i<n;i++){
            dp[i] = min(dp[p2]*2,min(dp[p3]*3,dp[p5]*5));
            //找到dp[i] 是从那个乘出来的，将资格位往前推一位
            if(dp[i] == dp[p2] * 2) p2++;
            if(dp[i] == dp[p3] * 3) p3++;
            if(dp[i] == dp[p5] * 5) p5++;
        }
        return dp[n-1];
    }
};

#include <queue>
#include <unordered_set>
class Solution {
public:
    int nthUglyNumber(int n) {
        int prime[3] = {2,3,5};
        priority_queue<long,vector<long>,greater<long>> heap;
        unordered_set<long> hash;
        hash.insert(1);
        heap.push(1);
        long res = 0;
        for(int i = 0;i < n;i++){
            auto cur = heap.top();
            heap.pop();
            res = cur;
            for(auto p:prime){
                long next = cur * p;
                if(!hash.count(next)){
                    hash.insert(next);
                    heap.push(next);
                }
            }
        }
        return res;
    }
};