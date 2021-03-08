#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int a[N],r[N];


//枚举区间右端点,对于每一个右端点去找他的最左端点
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d",&a[i]);
    }
    int ans = 1;
    for(int i=0,j = 0;i < n;++i){
        //前一个区间结束时没有重复的数的
        //新加一个数a[i]进来如果有重复的一定是a[i]
        r[a[i]]++;
        while(r[a[i]] > 1){
            r[a[j]]--;
            j++;
        }
        ans = max(ans,i - j + 1);
    }
    cout << ans;
    return 0;
}