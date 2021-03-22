#include <iostream>
//字符串哈希假定我们人品足够好，一般不会冲突
//把一个字符串看作是p进制的数，然后mod 2 ** 64映射到一个有限区间。
//一般取 p = 131或者1331的时候这个冲突极致的小 


//减少代码，开ULL，等价于 % 2 ** 64
typedef unsigned long long ULL;

using namespace std;

int P = 131;

const int N = 1e5 + 10;

char str[N];

//h记录哈希值，p记录p的i次方，减少计算
ULL h[N],p[N];


int get(int l,int r){
    return h[r] - h[l - 1] * p[r - l + 1];
}


int main(){
    int m,n;
    scanf("%d%d%s",&n,&m,str+1);
    p[0] = 1;
    for(int i = 1;i <= n;i++){
        p[i] = p[i - 1] * P;
        h[i] = h[i-1] * P + str[i];
    }
    while(m--){
        int l1,r1,l2,r2;
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
        if(get(l1,r1) == get(l2,r2)) puts("Yes");
        else puts("No");
    }
    return 0;
} 