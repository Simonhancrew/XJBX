#include <iostream>
#include <algorithm>

//将绝对值不等式分组，（1，n）,直觉放在中间是最小的
//将绝对值分组之后，发现这个点在每个区间中就是最短的，就是两端的距离

using namespace std;

const int N = 1e5 + 10;
int t[N];

int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> t[i];
    }
    sort(t,t + n);
    int res = 0;
    for(int i = 0, j = n -1;i <=j;i++,j--){
        res += t[j] - t[i];        
    }
    cout << res << endl;
    return 0;
}