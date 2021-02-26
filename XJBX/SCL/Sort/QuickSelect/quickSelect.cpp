#include <iostream>
using namespace std;


/*
    如果用快排的话是O(nlogn)的时间复杂度
    快速选择排序的时间复杂度是O(n)的
    基于前面的快排模板，我们需要知道第k个数在那半边就可以了，不用去完整的排序。
    所以左半边有的sl = j-l+1个数，只要这个值大于k就在这般部分递归
    否则我们需要去另一半区间查找，此时因为少了一个区间，即在另一半区间中找到第k - sl大的数
*/
const int N = 1e5 + 10;
int q[N];

int quickSelect(int k,int l,int r){
    if (l == r){
        return  q[l]; 
    }
    int x = q[l],i = l -1,j = r + 1;
    while(i < j){
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if(i < j) swap(q[i],q[j]);
    }
    //左边有多少个数
    int sl = j - l + 1;
    if(k <= sl){
        return quickSelect(k,l,j);
    }else{
        return quickSelect(k,j+1,r);
    }
}

int main (){
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i = 0;i < n;i++){
        scanf("%d",&q[i]);
    }
    int ans = quickSelect(k,0,n-1);
    printf("%d",ans);
    return 0;
}