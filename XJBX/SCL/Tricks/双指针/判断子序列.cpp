#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int a[N],b[N];

int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0;i < n;i++) scanf("%d",&a[i]);
    for(int i = 0;i < m;i++) scanf("%d",&b[i]);
    
    int j = 0;
    for(int i = 0;i < m;i++){
        if(j < n && a[j] == b[i]){
            j++;
        }
    }
    if(j == n){
        printf("Yes");
    }else{
        printf("No");
    }
    return 0;
}