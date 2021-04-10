#include <iostream>
#include <queue>

//哈夫曼树，
//最小的值一定在树的底部，且互为兄弟。
//每次我们找到最小的两个值合并，记录，然后重新入堆

using namespace std;

int main(){
    int n;
    priority_queue<int,vector<int>,greater<int>> heap;
    cin >> n;
    while(n--){
        int a;
        cin >> a;
        heap.push(a);
    }
    int res =0;
    while(heap.size() > 1){
        int a1 = heap.top();
        heap.pop();
        int a2 = heap.top();
        heap.pop();
        heap.push(a1 + a2);
        res += a1 + a2;
    }
    cout << res << endl;
    return 0;
}