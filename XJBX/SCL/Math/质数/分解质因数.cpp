#include <iostream>

using namespace std;

//根据算术基本定理，不考虑排列顺序的情况下，每个正整数都能够以唯一的方式表示成它的质因数的乘积
//n中最多只包含一个大于sqrt(n)的质数
//底数一定是质数
void divide(int x){
    //注意这里是小于等于
    for(int i = 2;i <= x / i;i++){
        if(x % i == 0){
            int s = 0;
            while(x % i == 0){
                x /= i;
                s++;
            }
            cout << i  << ' ' << s << endl;
        }
    }
    if (x > 1) printf("%d %d\n",x,1);
    puts("");
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int t;
        cin >> t;
        divide(t);
    }
    return 0;
}