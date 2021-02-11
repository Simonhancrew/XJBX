#include <vector>
#include <queue>
using namespace std;
class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> que;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num:nums){
            add(num);
        }
    }
    
    int add(int val) {
        que.push(val);
        if(que.size() > k){
            que.pop();
        }
        return que.top();
    }
};
