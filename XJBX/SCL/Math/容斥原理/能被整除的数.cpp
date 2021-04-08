#include <iostream>

//韦恩图
//根据容斥原理，等于单个集合的总数 - 两个集合的交集 + 。。。。
//不需要去关注每个集合元素的具体值，只需要去关注一个集合有多少个元素
//如何挑选集合，此处挑选集合使用二进制枚举，每一位的0或1代表有没有选择这个集合

using namespace std;
using LL = long long;

const int N = 20;

int p[N];


int main(){
    int m,n;
    cin >> n >> m;
    for(int i = 0;i < m;i++) cin >> p[i];
    
    int res = 0;
    //位枚举状态，至少选中一个集合
    for(int i = 1;i < 1 << m;i++){
        int t = 1,s = 0;//t是选中的质数的乘积，s是选中的集合数目
        for(int j = 0;j < m;j++){
            if(i >> j & 1){
                //乘积过大，不会存在整除的数
                if((LL)t * p[j] > n){
                    t = -1;
                    break;
                }
                s++;
                t *= p[j];
            }
        }
        if(t == -1) continue;
        if(s & 1) res += n / t;
        else res -= n / t;
    }
    cout << res << endl;
    return 0;
}
//此题还可以选用dfs去做