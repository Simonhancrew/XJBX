#include <vector>
#include <deque>
using namespace std;
//形如滑动窗口求最值，考虑单调队列单调栈
//单调队列的应用
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        singleQue que;
        vector<int> result;
        for(int i =0;i<k;i++){
            que.push(nums[i]);
        }
        result.push_back(que.front());
        for(int i = k;i<nums.size();i++){
            //去掉头元素
            que.pop(nums[i-k]);
            //弹入尾元素
            que.push(nums[i]);
            result.push_back(que.front());
        }
        return result;
    }
private:
    //一个单调队列的push和pop遵从一定的规则
    //这样能保证队列的头永远是最大的数
    //是指上这个队列并没有维护所有的值
    class singleQue{
    public:
        deque<int> que;
        //pop之前检查队列是否为空
        //检查当前需要弹出的数值是否是队列头的数值，如果是的话就需要弹出
        void pop(int value){
            if(!que.empty() && value == que.front()){
                que.pop_front();
            }
        }
        //如果push的元素大于back的元素，则将back的元素pop掉
        //直到push的数值小于等于back处的数值
        void push(int value){
            while(!que.empty() && value > que.back()){
                que.pop_back();
            }
            que.push_back(value);
        }

        int front(){
            return que.front();
        }
    };
};


//优先队列
#include <queue>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> que;
        for(int i = 0;i < k;++i){
            que.push({nums[i],i});
        }
        vector<int> res;
        //不要忘记最开始push一头
        res.push_back(que.top().first);
        for(int i = k;i < nums.size();++i){
            que.push({nums[i],i});
            while(!que.empty() && que.top().second <= i - k){
                que.pop();
            }
            res.push_back(que.top().first);
        }
        return res;
    }
};