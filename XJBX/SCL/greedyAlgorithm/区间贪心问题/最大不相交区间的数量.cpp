#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

//还是排序右端点，然后找到不重合的区间数目

const int N = 1e5 + 10;
struct Range{
    int l,r;
    bool operator< (const Range &w)const{
        return r < w.r;
    }
}range[N];

int main(){
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i ++ ){
        int l,r;
        scanf("%d%d",&l,&r);
        range[i] = {l,r};
    }
    sort(range,range + n);
    int res = 0,ed = -2e9;
    for (int i = 0; i < n; i ++ ){
        if(range[i].l > ed){
            res ++;
            ed = range[i].r;
        } 
    }
    cout << res << endl;
    return 0;
}