#include <iostream>
using namespace std;

const int N = 1e5 + 10;


int a[N],s[N];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    //注意边界处理，从1开始
    for(int i = 1; i <= n;++i) scanf("%d",&a[i]); 
    for(int i = 1; i <= n;++i){
        s[i] = s[i - 1] + a[i];
    }
    for(int i = 0;i < m;++i){
        int l ,r;
        scanf("%d%d",&l,&r);
        int ans = s[r] - s[l - 1];
        printf("%d\n",ans);
    }
    return 0;
}