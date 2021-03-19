#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

//因为要删除第k个插入的数，所以需要开两个映射记录从插入的数的下标找到在堆中的下标
//和堆中数的下标映射到第k个插入的数
const int N = 1e5 + 10;
int h[N],ph[N],hp[N],idx;


void heap_swap(int a,int b){
    //顺序无所谓，堆交换
    //交换插入数的下标映射到堆的下标
    swap(ph[hp[a]],ph[hp[b]]);
    //交换从堆下标到插入的数的映射
    swap(hp[a],hp[b]);
    //交换堆内的值
    swap(h[a],h[b]);
}

//将siftdown到底部
void down(int x){
    int t = x;
    if(2 * x <= idx && h[2 * x] < h[t]) t = 2 * x;
    if(2 * x + 1 <= idx && h[2 * x + 1] < h[t]) t = 2 * x + 1;
    if(t != x){
        heap_swap(t,x);
        down(t);
    }
}

//新插入的数，构建一下堆
void up(int u){
    while(u / 2 && h[u / 2] > h[u]){
        heap_swap(u,u / 2);
        u = u / 2;
    }
}

int main(){
    int n,m = 0;
    scanf("%d",&n);
    //利用m记录插入数的下标
    while(n--){
        string op;
        int k,x;
        cin >> op;
        if(op == "I"){
            scanf("%d",&x);
            m++,idx++;
            //更新各个映射
            ph[m] = idx,hp[idx] = m,h[idx] = x;
            up(idx);
        }else if (op == "PM") printf("%d\n",h[1]);
        else if(op == "DM"){
            heap_swap(1,idx);
            idx--;
            down(1);
        }else if (op == "D"){
            scanf("%d",&k);
            k = ph[k];
            heap_swap(k,idx);
            idx--;
            //这仅仅只是一个堆，并不是一个已经排序好的数组
            //新换来的元素是有可能up也有可能down的
            down(k),up(k);
        }else{
            scanf("%d%d",&k,&x);
            k = ph[k];
            h[k] = x;
            down(k),up(k);
            
        }
    }
    return 0;
}