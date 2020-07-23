#include <queue>
using namespace std;
class Solution{
    priority_queue<int> small_queue;
    priority_queue<int,greater<int>> big_queue;
public:
    void addNum(int num){
        small_queue.push(num);
        big_queue.push(small_queue.top());
        small_queue.pop();
        if(small_queue.size()<big_queue.size()){
            small_queue.push(big_queue.top());
            big_queue.pop();
        }
    }
    double findMedian(){
        return small_queue.size()>big_queue.size()?small_queue.top():(small_queue.top()+big_queue.top())>>1;
    }


};
