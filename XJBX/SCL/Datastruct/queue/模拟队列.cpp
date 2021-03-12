#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int que[N],hh,tt = -1;

//往队尾部插入
void push(int x){
    que[++tt] = x;
}

//弹出队列的头部
void pop(){
    hh++;
}

bool empty(){
    if(hh <= tt){
        return false;
    }
    return true;
}

int query(){
    return que[hh];
}

int main(){
    int n;
    cin >> n;
    while(n--){
        string op;
        cin >> op;
        int x;
        if(op == "push"){
            cin >> x;
            push(x);
        }else if (op == "pop"){
            pop();
        }else if(op == "empty"){
            
            cout << (empty()?"YES":"NO") << endl;
        }else{
            if (hh <= tt){
                cout << que[hh]<<endl;
            }
        }
    }
    return 0;
}