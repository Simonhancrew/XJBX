#include <iostream>

using namespace std;

//数组模拟栈


const int N = 1e5 + 10;

int stk[N],tt;

void push(int x){
    stk[++tt] = x;
}

void pop(){
    tt--;
}

int top(){
    return stk[tt]; 
}

bool empty(){
    return tt == 0;
}

int main(){
    int m;
    cin >> m;
    while(m--){
        string op;
        int x;
        cin >> op;
        if(op == "push"){
            cin >> x;
            push(x);
        }else if(op == "pop"){
            pop();
        }else if (op == "empty"){
            cout << (empty()?"YES":"NO") << endl;
        }else {
            cout << top() << endl;
        }
    }


    return 0;
}
