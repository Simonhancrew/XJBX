#include <vector>
using namespace std;
//可以证明，x-y,y是第一个无法到达的加油站，那么在xy之间的加油站作为下一个起点
//也是无法做到全部到达的，所以从y+1开始就可以了
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = 0;
        while(i < n){
            int sumOfGas = 0,sumOfCost = 0;
            int cnt = 0;
            while(cnt < n){
                int j = (i + cnt) % n;
                sumOfGas += gas[j];
                sumOfCost += cost[j];
                //花费大于油，i= i+cnt+1
                if(sumOfCost > sumOfGas){
                    break;
                }
                ++cnt;
            }
            //cnt == n说明能够完整的走完，结束
            if(cnt == n){
                return i;
            }else{
                i = i + cnt + 1;
            }
        }
        return -1;
    }
};