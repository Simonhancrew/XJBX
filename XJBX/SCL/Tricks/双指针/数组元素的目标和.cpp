#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int A[N],B[N];

int main(){
    int m,n,x;
    cin >> n >> m >> x;
    for(int i = 0;i < n;i++){
        scanf("%d",&A[i]);
    }
    
    for(int i = 0;i < m;i++){
        scanf("%d",&B[i]);
    }
    
    //因为单调，这里可以一个从头开始，一个从尾部开始
    //去凑这个坐标点
    for(int i = 0,j = m -1 ;i < n;i++){
        while(j >= 0 && A[i] + B[j] > x) j--;
        if(A[i] + B[j] == x){
            printf("%d %d",i,j);
            break;
        } 
    }
    return 0;
}