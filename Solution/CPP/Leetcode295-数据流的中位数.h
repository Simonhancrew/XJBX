#include <queue>
using namespace std;
//最小堆储存大的一半的数，最大堆储存小的一般的数
//保证小的一半数字所在的堆时比更大的一半的堆多一的
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    priority_queue<int> small;
    priority_queue<int,vector<int>,greater<int>> big;
    void addNum(int num) {
        small.push(num);
        big.push(small.top());
        small.pop();
        if(small.size() < big.size()){
            small.push(big.top());
            big.pop();
        }
    }
    
    double findMedian() {
        if(small.size() > big.size()){
            return small.top();
        }
        return (double)(small.top() + big.top())/ 2;
    }
};
