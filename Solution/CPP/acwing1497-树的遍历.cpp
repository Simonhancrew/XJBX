#include <iostream>
#include <unordered_map>
#include <queue>
//一定要给定中序遍历才能唯一的还原一颗树
//前中序找到root是那一个，然后去中序找到root的位置，左边就是左子树，右边就是右子树
using namespace std;

const int N = 40;
int n;
int post[N],in[N];
unordered_map<int,int> l,r,pos;

int build(int il,int ir,int pl,int pr){
    //后序最后是根
    int root = post[pr];
    //中序找到根
    int k = pos[root];
    //在后序中的左子树和中序中的左子树长度是一样的
    if(il < k) l[root] = build(il,k-1,pl,pl+k-1-il);
    if(k < ir) r[root] = build(k+1,ir,pl+k-il,pr - 1);
    return root;
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    while(q.size()){
        auto t = q.front();
        q.pop();
        cout << t << ' ';
        if(l.count(t)) q.push(l[t]);
        if(r.count(t)) q.push(r[t]);
    }    
}


int main(){
    cin >> n;
    for(int i = 0;i < n;i++) cin >> post[i];
    for(int i = 0;i < n;i++) {
        cin >> in[i];
        pos[in[i]] = i;
    }
    int root = build(0,n-1,0,n-1);
    bfs(root);
    return 0;
}