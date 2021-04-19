#include <iostream>
#include <algorithm>

//还是考虑最后一步，拿不拿，拿的话，他之前的那个状态是哪一个？一定是比当前小的，我们求的是当前位置作为结尾的最长序列
//所以需要去前面遍历一下比他下的元素，然后每个状态+1看谁是最大的
//不同于之前的dp，此处我们要遍历一下每个位置结尾的最大值才能拿到最大的上升序列

using namespace std;

const int N = 1e3 + 10;
int dp[N];
int a[N];


int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    
    
    for(int i = 1;i <= n;i++){
        dp[i] = 1;
        for(int j = 1;j < i;j++){
            if(a[j] < a[i]){
                dp[i] = max(dp[i],dp[j] + 1);
            }
        }
    }
    int res = 0;
    for(int i = 1;i <+ n;i++) res = max(dp[i],res);
    cout << res << endl;
    return 0;
}