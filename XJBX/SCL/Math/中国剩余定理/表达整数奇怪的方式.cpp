#include <iostream>
#include <algorithm>

//利用扩展中国剩余定理。变形公式利用exgcd

using LL = long long;

using namespace std;

const int N = 35;


LL exgcd(LL a, LL b,LL& x,LL& y){
    if(!b){
        x = 1,y = 0;
        return a;
    }
    LL d = exgcd(b,a%b,y,x);
    y -= a / b * x;;
    return d;
}


int main(){
    int n;
    cin >> n;
    LL a1,m1;
    cin >> a1 >> m1;
    bool has_answer = true;
    //不断地去合并方程
    for(int i = 1;i < n;i++){
        LL a2,m2;
        cin >> a2 >> m2;

        LL k1,k2;
        LL d = exgcd(a1,a2,k1,k2);
        //有解判断
        if((m2-m1) % d){
            has_answer = false;
            break;
        }
        //把公约数扩大，让左边的系数变正确
        k1 *= (m2 - m1) / d;
        //存下a2 / d
        LL t = a2 / d;
        //让k1变成最小正整数解，只要去除a2/d的影响就可以了
        //但是我们不知道此时他的正负情况，所以要考虑绝对值
        //c++处理绝对值拿到数学的mod值如下
        k1 = (k1 % t + t) % t;
        
        m1 = a1 * k1 + m1;
        a1 = abs(a1 / d * a2);
        
    }
    if (has_answer){
        //负数处理方法
        cout << (m1 % a1 + a1) % a1 << endl;
    }
    else puts("-1");
    return 0;
}