#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//对每个数，如果是约数，可以找到两个
//从小到大枚举搜友较小的约数

vector<int> get_divisors(int n){
    vector<int> res;
    for(int i = 1;i <= n / i;i++){
        if(n % i == 0){
            res.push_back(i);
            if(i != n / i) res.push_back(n / i);
        }
    }
    sort(res.begin(),res.end());
    return res;
}


int main(){
    int n;
    cin >> n;
    while(n--){
        int a;
        cin >> a;
        auto res = get_divisors(a);
        for(auto &num:res){
            printf("%d ",num);
        }
        puts("");
    }
    return 0;
}