#include <iostream>
#include <cstring>

//匈牙利算法只需要存储单边就可以了，我们只从一个集合出发看连边情况
//如果可以连接就连接，不能链接就看看之前的链接能不能改，让改完之后两者都能链接
//所以可以理解成一个男生不放弃的追另一个渣男女朋友的，渣男可以有备胎选择，然后渣男和胚胎在一起了
//另一个男生和他追求的女生在一起了。

using namespace std;


const int N = 510,M = 1e5 + 10;
int n1,n2,m;
int h[N],e[M],ne[M],idx;
int match[N];
//st为标记右边的有没有被找过，在某次发生冲突的时候，之前的冲突节点能继续递归的去找匹配
//此时他不能再找之前的匹配项了
bool st[N];

void add(int a,int b){
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

bool find(int x){
    for(int i = h[x];i != -1;i = ne[i]){
        int j = e[i];
        if(!st[j]){
            //当前左边找右边的时候，标记右边的已经被匹配
            //右边没有匹配过，成功
            //如果此次和之前冲突的匹配能在更换依然成功匹配，则还是成功的
            st[j] = true;
            if(match[j] == 0 || find(match[j])){
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main(){
    cin >> n1 >> n2 >> m;
    
    memset(h,-1,sizeof h);
    
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
    }
    
    int res = 0;
    //从左往右找匹配
    for(int i = 1;i <= n1;i++){
        //每次开始都是全部没找过的
        //match中是记录着右到左的信息
        memset(st,false,sizeof st);
        if(find(i)) res++;
    }

    printf("%d",res);

    return 0;
}