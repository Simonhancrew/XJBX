#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int h[N],idx;

void down(int u){
    //记录当前三个节点的最小值节点
    int t = u;
    if(2 * u <= idx && h[2 * u] < h[t]) t = 2 * u;
    if(2 * u + 1 <= idx && h[2 * u + 1] < h[t]) t = 2 * u + 1;
    if(t != u){
        swap(h[t],h[u]);
        down(t);
    }
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    //初始化堆
    for(int i = 1;i <= n;i++) scanf("%d",&h[++idx]);
    //一个一个的插入再down是nlogn的，我们可以一次完全插入
    //利用堆的性质，从倒数第二层最后一个开始down，这样保证了堆顶一定是最小的
    for(int i = n / 2;i >= 1;i--) down(i);
    //删除堆顶的操作，因为数组头部不太好删除，我们将头部和尾部交换，然后删除尾部
    //之后再把头siftdown到应该在的位置
    while(m--){
        printf("%d ",h[1]);
        h[1] = h[idx];
        idx--;
        down(1);
    }
    return 0;
}