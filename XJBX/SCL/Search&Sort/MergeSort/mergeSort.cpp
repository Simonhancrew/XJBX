#include <iostream>
using namespace std;

//归并排序分为三步
//1 选中间点
//2 归：递归的排序左半边的右半边
//3 并：利用一个额外的数组，合并两个已经排序的部分

const int N= 1e5 + 10;
int q[N],temp[N];

//自底向上
void mergeSort(int q[],int l,int r){
    if(l >= r){
        return;
    }

    // >>的优先级是低于+的
    int mid = l + r >> 1;
    //不建议使用mid - 1 分割
    //因为向下取整的话，造成mid+1,r这个区间循环不变
    mergeSort(q,l,mid), mergeSort(q,mid+1,r);
    int k = 0,i = l,j = mid+1;
    //把排序信息记录到缓存数组
    while(i <=mid && j <= r){
        //稳定排序在此处
        if(q[i] <= q[j]){
            temp[k++] = q[i++];
        }else{
            temp[k++] = q[j++];
        }
    }
    while(i <= mid) temp[k++] = q[i++];
    while(j <= r) temp[k++] = q[j++];
    //复原的操作，注意复原的区间是从l->r
    //不同的递归深度的的区间是不同的
    //所以要严格按照区间去合并数组
    for(int i = l,j = 0;i <= r;i++,j++){
        q[i] = temp[j];
    }
} 


int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d",&q[i]);
    }
    mergeSort(q,0,n-1);
    for(int i = 0;i < n;i++){
        printf("%d ",q[i]);
    }
    return 0;
}