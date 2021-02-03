#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
//设计一个结构，能在一边push和pop的过程中找到中位数
//或者用multiset的特性去插入和删除
class medianFinder{
public:
    medianFinder(int input):k(input),bigsize(0),smallsize(0){}
    void addnums(int num){
        //推入的时候比最大堆顶小的推最大堆，否则最小堆
        if(small.empty() || num <= small.top()){
            small.push(num);
            smallsize++;
        }else{
            big.push(num);
            bigsize++;
        }
        //对于失衡做一次平衡
        makebalance();
    }
    void erase(int num){
        //延迟删除，记录要删除元素的次数
        //到达对顶的时候，他对答案时做出贡献的，我们不需要这个贡献
        //直接移去
        ++delay[num];
        if(num <= small.top()){
            smallsize--;
            if(num == small.top()){
                prune(small);
            }
        }else{
            bigsize--;
            if(num == big.top()){
                prune(big);
            }
        }
        //删除时候失衡的平衡
        makebalance();
    }
    double findmeidian(){
        return k & 1 ? small.top(): ((double)small.top() + big.top()) / 2.0;
    }
    //堆顶的检测，保证堆顶的元素是不需要被删除的元素，在makebalance里被调用
    template<typename T>
    void prune(T& heap){
        while(!heap.empty()){
            int tt = heap.top();
            if(delay.count(tt)){
                --delay[tt];
                if(!delay[tt]){
                    delay.erase(tt);
                }
                heap.pop();
            }else{
                break;
            }
        }
    }
    void makebalance(){
        if(smallsize > bigsize + 1){
            big.push(small.top());
            small.pop();
            bigsize++;
            smallsize--;
            //堆顶的元素在做完插和删之后不会无效
            //对于堆顶的元素做一次检测
            prune(small);
        }else if (smallsize < bigsize){
            small.push(big.top());
            smallsize++;
            bigsize--;
            big.pop();
            prune(big);
        }
    }

private:
    //最大堆存小的一半的数
    priority_queue<int> small;
    //最小堆存大的一半的数
    priority_queue<int,vector<int>,greater<int>> big;
    int smallsize,bigsize;
    int k;//窗口大小
    unordered_map<int,int> delay;
};
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        medianFinder mf(k);
        vector<double> ans;
        for(int i = 0;i < k;i++){
            mf.addnums(nums[i]);
        }
        ans.push_back(mf.findmeidian());
        for(int i = k;i < nums.size();i++){
            mf.addnums(nums[i]);
            mf.erase(nums[i-k]);
            ans.emplace_back(mf.findmeidian());
        }
        return ans;
    }
};