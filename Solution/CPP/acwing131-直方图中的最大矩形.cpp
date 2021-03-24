#include <iostream>
#include <algorithm>
using namespace std;

//枚举每一个每一个矩形当前的高度能够往两边扩多宽
//此时我们要找到左右两边第一个高度比他小的矩形
//完全就是单调栈模板的应用

const int N = 1e5 + 10;

typedef long long LL;
int q[N],l[N],r[N],h[N];
int n;

int main(){
    while(scanf("%d",&n),n){
        for(int i = 1;i <= n;i++) cin >> h[i];
        //左右边界-1，可以在单调栈里少一个if
        h[0] = -1;
        h[n + 1] = -1;
        //单调栈维护左边（注意存的是坐标）
        int tt = 0;
        q[0] = 0;
        for(int i = 1;i <= n;i++){
            while(h[i] <= h[q[tt]]) tt--;
            l[i] = q[tt];
            q[++tt] = i;
        }
        //单调栈维护右边
        tt = 0;
        q[0] = n + 1;
        for(int i = n;i >= 1;i--){
            while(h[i] <= h[q[tt]]) tt--;
            r[i] = q[tt];
            q[++tt] = i;
        }
        //考虑一下数据溢出 10**9 * 10**9
        LL res = 0;
        for(int i = 1;i <= n;i++){
            res = max(res,(LL)h[i] * (r[i] - l[i] - 1));
        }
        cout << res << endl;
    } 
    return 0;
}