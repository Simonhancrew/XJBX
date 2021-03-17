#include <iostream>
#include <algorithm>

//首先想最暴力的解法，就是两重循环，逐个判断每对异或之后找到最大的
//优化的想法来自于这个数的二进制表示，我们用trie树存下每一个出现的数，然后从高位到低位，尽量选择每一位与他不相同的数
//理解异或最简单的方法就是把他理解成不进位加法
//这样我们就可以拿到每个数的最大异或，之后比较一下就行了
using namespace std;

const int N = 1e5 +10,M = 31 * N;

int son[M][2],idx;

void insert(int x){
    int p = 0;
    for (int i = 30;i >= 0;i--){
        int u = x >> i & 1;
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
}

int query(int x){
    int p = 0,res = 0;
    for(int i = 30;i >= 0;i--){
        int u = x >> i & 1;
        if(son[p][!u]){
            res = res * 2 + !u;
            p = son[p][!u];
        }else{
            res = res * 2 + u;
            p = son[p][u];
        }
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    int res = 0;
    for(int i = 0;i < n;i++){
        int cur;
        scanf("%d",&cur);
        insert(cur);
        int t = query(cur);
        res = max(res,cur ^ t);
    }
    cout << res << endl;
    return 0;
}