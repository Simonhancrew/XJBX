#include <iostream>
#include <algorithm>

//按照w + s的值去排序,按照从大到小的去寻找，重量递增，找到最小的最大风险值
using namespace std;

const int N = 5e4 + 10;
struct Cow{
    int s,w;
    bool operator< (const Cow& c){
        return s + w < c.w+ c.s;
    }
}cow[N];

int main(){
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        int s,w;
        cin >> w >> s;
        cow[i] = {s,w};
    }
    sort(cow,cow + n);
    int res = -2e9,sum = 0;
    for(int i = 0;i < n;i++){
        res = max(res,sum - cow[i].s);
        sum += cow[i].w;
    }
    cout << res << endl;
    return 0;
}