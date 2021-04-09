#include <iostream>
#include <cstring>
#include <unordered_set>

/*

设S表示一个非负整数集合.定义mex(S)为求出不属于集合S的最小非负整数运算,即:
mes(S)=min{x};
例如:S={0,1,2,4},那么mes(S)=3;

在有向图游戏中,对于每个节点x,设从x出发共有k条有向边,分别到达节点y1,y2,····yk,定义SG(x)的后记节点y1,y2,····
yk的SG函数值构成的集合在执行mex运算的结果,即:
SG(x)=mex({SG(y1),SG(y2)····SG(yk)})
特别地,整个有向图游戏G的SG函数值被定义为有向图游戏起点s的SG函数值,即 SG(G)=SG(s).



*/
using namespace std;

const int N = 110,M = 10010;
int p[M],s[N];
int n,m;

int sg(int x){
    //记忆化搜索
    if(p[x] != -1) return p[x];
    unordered_set<int> S;
    //对于可以拿的石子数做搜索，如果在某堆石头中这个数可以拿去
    //递归的算他的sg函数，然后将这个sg函数加入到集合中，留待后续计算mex，返回当前节点的sg值
    for(int i = 0;i < n;i++){
        int sum = s[i];
        if(x >= sum) S.insert(sg(x - sum));
    }
    //完成S集合之后求mex
    for (int i = 0;;i++){
        if(!S.count(i)){
            return p[x] = i; 
        }
    }
}


int main(){
    cin >> n;
    for(int i = 0;i < n;i++) cin >> s[i];
    
    cin >> m;
    int res = 0;
    memset(p, -1, sizeof p);
    while(m--){
        int x;
        cin >> x;
        res ^= sg(x);
    }
    if(res) puts("Yes");
    else puts("No");
    return 0;
}