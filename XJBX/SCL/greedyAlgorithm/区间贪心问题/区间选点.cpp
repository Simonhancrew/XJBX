#include <iostream>
#include <algorithm>

//区间贪心没有绝对的套路，
//大部分的需要按照区间某个端点排序再去尝试

using namespace std;

const int N = 1e5 + 10;
int n;
struct Range{
    int l,r;
    bool operator< (const Range& w){
        return r < w.r;
    }
}range[N];

//按照右端点排序，选择右端点，尽可能的覆盖多的区间。
//这样我到了一个左端点比上次右端点大的值的时候说明出现了断点，无法覆盖
//需要新加入一个点

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ){
        int l,r;
        cin >> l >> r;
        range[i] = {l,r};
    }
    sort(range,range + n);
    //ed记录上次的右端点
    int res = 0,ed = -2e9;
    for (int i = 0; i < n; i ++ ){
        if(range[i].l > ed){
            ed = range[i].r;
            res++;
        }
    }
    cout << res << endl;
    return 0;
}