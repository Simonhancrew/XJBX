#include <iostream>
#include <algorithm>

//按照左端点从小到大排序，之后找到包含start点且右端点最大的区间，
//更新start为这个区间的右端点的值


using namespace std;

const int N =  1e5 + 10;

struct Range{
    int l,r;
    bool operator< (const Range &w)const{
        return l < w.l;
    }
}range[N];
int start,ed;

int main()
{
    cin >> start >> ed;
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        int l,r;
        cin >> l >> r;
        range[i] = {l,r};
    }
    
    sort(range,range + n);
    
    int res = 0;
    bool flag = false;
    for(int i = 0;i < n;i++){
        int j = i,r = -2e9;
        while(j < n && range[j].l <= start){
            r = max(r,range[j].r);
            j++;
        }
        if(r < start){
            break;
        }
        res ++;
        if(r >= ed){
            flag = true;
            break;
        }
        i = j - 1;
        start = r;
    }
    
    if(flag) cout << res << endl;
    else cout << -1 << endl;
    
    return 0;
}