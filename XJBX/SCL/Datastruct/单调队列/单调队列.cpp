#include <iostream>


// 这道题首先是单调队列的一个经典应用，注意队列里存的是数组的下标，这样有利于删除过期的数组元素（头部）
// 其次，注意构造单调增的队列去找最小元素，单点减的队列去找最大元素
// 最后，要注意push入新元素之后再去从队列中找队首（因为新加入的元素可能是要求的值
using namespace std;

const int N = 1e6 + 10;
int a[N],q[N];

//队列里存的是输入数组的下标，注意这个手法

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i = 0;i < n;++i) scanf("%d",&a[i]);

    int hh = 0,tt = -1;
    for(int i = 0;i < n;i++){
        //队列不为空且队首元素没有超出范围
        if (hh <= tt && i - k + 1 > q[hh]) hh++;

        //队列不空，且队尾元素小于新元素，保证单调递减
        while(hh <= tt && a[q[tt]] >= a[i]) tt--;

        q[++tt] = i;

        if(i >= k-1) printf("%d ",a[q[hh]]);
    }
    
    puts("");

    hh = 0,tt = -1;
    for(int i = 0;i < n;i++){
        if(hh <= tt && i - k + 1 > q[hh]) hh++;

        while(hh <= tt && a[q[tt]] <= a[i]) tt--;

        q[++tt] = i;

        if (i >= k - 1) printf("%d ",a[q[hh]]);
    }
    return 0;
}