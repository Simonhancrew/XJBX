#include <iostream>
#include <cstring>
#include <queue>

//如果是一个稀疏图，点数超级多的话，用朴素的做法会爆
//我们需要找一找优化的思路，首先我们会拿到不在最短距离集合中的最近点，我们采用遍历的思路去拿到这个数的
//但是考虑一个最小堆的话，我们可以O(1)的拿到这个离起点最近的点

using namespace std;

typedef pair<int,int> PII;

const int N = 150010;

int h[N],e[N],w[N],ne[N],idx;
int d[N];
bool st[N];
int n,m;

void add(int a,int b,int c){
    e[idx] = b,ne[idx] = h[a],w[idx] = c,h[a] = idx++;
}


int dijsktra(){
    memset(d,0x3f,sizeof d);
    d[1] = 0;
    
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,1});
    
    while(heap.size()){
        auto t = heap.top();
        heap.pop();
        int index = t.second,distance = t.first;
        
        if(st[index]) continue;
        st[index] = true;
        
        for(int i = h[index];i != -1;i = ne[i]){
            int j = e[i];
            if(d[j] > distance + w[i]){
                d[j] = distance + w[i]; 
                heap.push({d[j],j});
            }    
        }
    }
    if(d[n] == 0x3f3f3f3f) return -1;
    return d[n];
}


int main(){
    cin >> n >> m;
    memset(h,-1,sizeof h);
    while(m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }
    cout << dijsktra() << endl;
    return 0;
}
