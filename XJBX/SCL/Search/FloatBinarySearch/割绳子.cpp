//很多求最值问题可以变化为二分+判定问题
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e6 + 10;
const double eps = 1e-4;
int a[N];
int n,m;

bool check(double u){
    int cur = 0;
    for(int i = 1;i <= n;i++){
        cur += a[i] / u;
    }
    return cur >= m;
}

int main(){
    cin >> n >> m;
    int maxi = -1e9;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        maxi = max(maxi,a[i]);
    }
    double l = 0, r = maxi;
    while(r - l > eps){
        double mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid; 
    }
    printf("%.2lf",l);
    return 0;
}