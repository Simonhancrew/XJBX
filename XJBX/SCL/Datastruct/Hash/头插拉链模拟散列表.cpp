#include <iostream>
#include <cstring>

using namespace std;

//base选取质数
const int N = 1e5 + 10;

//后面利用数组模拟链表
int h[N],e[N],ne[N],idx;

void insert(int x){
    //取到x应该放到那个桶中
    int k = (x % N + N) % N;
    //首先把值放进链表坑中
    e[idx] = x;
    //确定当前链表指向h[k]当前的头部
    ne[idx] = h[k];
    //换h[k]的头
    h[k] = idx++;
}

bool find(int x){
    int k = (x % N + N) % N;  
    for(int i = h[k];i != -1;i = ne[i]){
        if(e[i] == x){
            return true;
        }
    }
    return false;
}


int main(){
    int n;
    cin >> n;
    //头插法，开始h[]中存的都是链表尾部
    memset(h,-1,sizeof(h));
    while(n--){
        //开op[2]是怕额外空格被坑
        char op[2];
        int x;
        scanf("%s%d",op,&x);
        if(op[0] == 'I'){
            insert(x);
        }else{
            if (find(x)){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        }
    }
    return 0;
}