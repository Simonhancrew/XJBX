#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int a[N],b[N];

//第一次构造差分数组的时候，
//将给的数组看作是空的，这样就等价于在区间[i,i]上插入c了
//代码复用度会高
void insert(int l,int r,int c){
    b[l] += c;
    b[r + 1] -= c;
}


int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i = 1;i <= m;i++) scanf("%d",&a[i]);
    
    for(int i = 1;i <= m;i++) insert(i,i,a[i]);

    for(int i = 0;i < n;i++){
        int l,r,c;
        scanf("%d%d%d",&l,&r,&c);
        insert(l,r,c);
    }   
    for(int i = 1; i <= m;i++) b[i] += b[i - 1];

    for(int i = 1;i <= m;i++) printf("%d ",b[i]);

    return 0;    
}