#include <iostream>

using namespace std;


//首先，链表一般都是struct node，但是在创建的时候new会很耗时
//所以在某些情况下可以用数组去模拟链表，在输入已知的情况下

const int N = 1e5 + 10;


//在这里，head是头节点下标，e[i]是储存的数值，ne[i]是当前节点的下一个节点
//idx表示已经用到了那个节点
int head,e[N],ne[N],idx;

void init(){
    head = -1;
    idx = 0;
}

//head其实是头节点的坐标
void addToHead(int x){
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}

//将x插入到下标k的后面
void add(int k ,int x){
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

//将下标是k的数后面的数移除
void remove(int k){
    ne[k] = ne[ne[k]];
}


int main(){
    int n;
    cin >> n;
    init();
    while(n--){
        int x,y;
        char op;
        cin >> op;
        if (op == 'H'){
            cin >> x;
            addToHead(x);
        }else if (op == 'D'){
            cin >> x;
            //为0的时候删除头节点
            if (!x){
                head = ne[head];
            }
            remove(x - 1);
        }else{
            cin >> x >> y;
            add(x-1,y);
        }
    }
    for (int i = head;i != -1;i=ne[i]){
        cout << e[i] << ' ';
    }
    cout << endl;
    return 0;
}