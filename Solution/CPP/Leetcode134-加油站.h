#include <vector>
using namespace std;
//暴力法
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i = 0;i < gas.size();++i){
            int rest = gas[i] - cost[i];
            int index = (i + 1) % gas.size();
            //环形循环可以考虑while的trick
            while(rest > 0 &&index != i){
                rest += gas[index] - cost[index];
                index = (index + 1) % gas.size();
            }
            if(rest >= 0 && index == i) return i;
        }
        return -1;
    }
};

//所有的gas和如果大于等于cost，则可以找到这个坐标
//从i最大走到j的话，则在(i,j)之间的坐标是无法走到一圈的，只能重新从j+1开始，可以证明
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for(int i = 0;i < gas.size();++i){
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if(curSum < 0){
                start = i + 1;
                curSum = 0;
            }
        }
        if(totalSum < 0) return -1;
        return start;
    }
};