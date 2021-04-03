#include <iostream>
#include <algorithm>

using namespace std;

//欧拉函数的证明用到了容斥原理
//1 给数分解质因数，然后拿到所有的质因子
//2 利用公式算结果


int main(){
    int n;
    cin >> n;
    while(n--){
        int a;
        cin >> a;
        int res = a;
        for(int i = 2;i <= a / i;i++){
            if(a % i == 0){
                res = res / i *(i - 1);
                while(a % i == 0) a /= i;
            }
        }
        if(a > 1) res = res / a * (a - 1);
        cout << res << endl;
    }
    return 0;
}