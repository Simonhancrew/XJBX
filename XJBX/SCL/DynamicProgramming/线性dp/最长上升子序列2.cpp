#include <iostream>
#include <algorithm>

//贪心 + 二分
//贪心的找到当前这个数之前不大于他的最小值，接在这个数的后面
//对此我们记录每一个长度的结尾的最大值

using namespace std;

const int N = 1e5 + 10;
int a[N],q[N];


int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0;i <= n;i++) scanf("%d", &a[i]);
    int len = 0;
    for(int i = 0;i < n;i++){
        int l = 0,r = len;
        //二分模板
        while(l < r){
            int mid = r + l + 1>> 1;
            //check的是比ai小，意味着去右边继续找
            //所以是小于ai的右端点
            if(q[mid] < a[i]) l = mid;
            else r = mid - 1;
        }
        len = max(r+1,len);
        q[r + 1] = a[i];
    }
    return 0;
}