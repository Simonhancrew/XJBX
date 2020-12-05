#include <vector>
#include <unordered_map>
using namespace std;
//贪心的选择剩下任务数最多的任务
//让cpu均匀的调度，确定最佳的下一个任务
//这个找法就是：
//既是找不在冷却中的任务，且该任务剩下的次数最多
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int all = tasks.size();
        if(n == 0){
            return all;
        }
        //任务和任务数的映射
        unordered_map<char,int> freq;
        for(auto task:tasks){
            ++freq[task];
        }
        //每个任务的下一个可以出现时间和剩下的该任务剩下的任务数
        vector<int> nextValid,rest;
        for(auto task:freq){
            nextValid.push_back(1);
            rest.push_back(task.second);
        }
        //不同的任务总数
        int m = freq.size();
        //不断+1模拟time的时间片，存在等待的时间就更新这个时间片
        int time = 0;
        for(int i = 0;i < all;++i){
            time++;
            //找到下一个可能的任务时间的最小值
            int minNextValid = INT_MAX;
            for(int j = 0;j < m;++j){
                //要确定任务还剩下
                if(rest[j]){
                    minNextValid = min(minNextValid,nextValid[j]);
                }
            }
            time = max(time,minNextValid);
            //找到确定需要执行的任务
            int best = -1;//trick,找自然数index
            for(int j = 0;j < m;++j){
                //任务还有，在可出现的时间范围内，即不在冷却中
                if(rest[j] && nextValid[j] <= time){
                    //贪心的选择尽可能剩下的多的先执行
                    if(best == -1 || rest[j] > rest[best]){
                        best = j;
                    }
                }
            }
            //更新下一次出现的时间和剩下的任务（更新冷却时间）
            nextValid[best] = time + n + 1;
            --rest[best]; 
        }
        return time;
    }
};