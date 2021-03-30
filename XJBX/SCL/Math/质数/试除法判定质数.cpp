#include <iostream>
#include <algorithm>
//质数定义：所有大于1的自然数，只包含1和本身这两个约数就被成为质数
//或者叫做素数
using namespace std;
//O(n)
bool is_prime_n(int n){
    if(n < 2) return false;
    for(int i = 2;i < n;i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

//O(sqrt(n))
bool is_prime(int n){
    if(n < 2) return false;
    //注意这里是小于等于
    for(int i = 2;i <= n / i;i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int t;
        cin >> t;
        if(is_prime(t)) cout << "Yes" <<endl;
        else cout << "No" << endl;
    }
    return 0;
}