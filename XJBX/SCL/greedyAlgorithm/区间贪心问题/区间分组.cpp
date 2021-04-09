#include <iostream>
#include <algorithm>
#include <queue>

//按照左端点排序，之后用小根堆记录最小的右端点的分组
//某个范围的左端点小于最小的maxr的时候，他一定无法进入任何分组，需要新开
//反之如果能进入的话，就更新堆顶的右端点值

using namespace std;

const int N = 1e5 + 10;

struct Range{
    int l,r;
    bool operator< (const Range &w)const {
        return l < w.l;
    }
}range[N];

int main(){
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        int l,r;
        cin >> l >> r;
        range[i] = {l,r};
    }
    sort(range,range + n);
    priority_queue<int,vector<int>,greater<int>> heap;
    for(int i = 0;i < n;i++){
        auto lr = range[i];
        if(heap.empty() || lr.l <= heap.top()){
            heap.push(lr.r);
        }else{
            auto t = heap.top();
            heap.pop();
            heap.push(lr.r);
        }
    }
    cout << heap.size() << endl;
    return 0;
}