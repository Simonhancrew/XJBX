#include <iostream>

using namespace std;

// 维护一个额外信息的并查集，带权并查集
// https://www.acwing.com/problem/content/242/
// 注意d可能是复数，所以需要维护的是距离的差距的模（可以考虑做一个取模的操作，令M = 3）

const int N = 5e5 + 10;
int p[N],d[N];

int find(int x){
    if(p[x] != x){
        //储存根节点tmp
        int tmp = find(p[x]);
        //更新当前节点到根节点的距离，递归之后d[p[x]]会是他的父节点和根节点之间的距离
        d[x] += d[p[x]];
        //换根
        p[x] = tmp;
    }
    return p[x];
}

int main(){
    int m,n;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <=n;i++) p[i] = i;
    int res = 0;
    while(m--){
        int t,x,y;
        scanf("%d%d%d",&t,&x,&y);
        if(x > n || y > n) res++;
        else{
            int px = find(x),py = find(y);
            if(t == 1){
                //在一个集合,看一下是不是一个类别
                if(px == py && (d[x] - d[y]) % 3) res++;
                else if (px != py){
                    //放入一个集合里
                    p[px] = py;
                    //更新原来x属于的树的头节点px的d[p[x]]
                    //既px到py的距离
                    //此时二者的距离应该相等
                    d[px] = d[y] - d[x]; 
                }
            }else{
                //在一个集合，判断真假，此时x到根的距离应该比y多1
                if(px == py && (d[x] - d[y] - 1) % 3) res++;
                else if(px != py){
                    //不在一个集合，更新一下吃的关系
                    p[px] = py;
                    //x到跟应该比y到根大1
                    d[px] = d[y] + 1 -d[x];// d[p2] = ((d[x] - d[y]) + M) % M;   
                }
            }
        }
    }
    printf("%d\n",res);
    return 0;
}