#include <iostream>

using namespace std;

//单调栈是一个容器内数据单调递增的结构（也可以递减）
//我们一般能最快的拿到一个数的左边第一个比他小的数（大）
const int N = 1e5 + 10;


//注意栈内的数据是从下标1开始存的
//这样判断是否为空直接看tt是否为0就可以了
//stk[++t] = x
int stk[N],tt;


int main(){
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        int x;
        cin >> x;
        while(tt && stk[tt] >= x) tt--;
        if(tt) cout << stk[tt] << ' ';
        else cout << -1 <<' ';
        stk[++tt] = x;
    }
    return 0;
}