#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int l[N],r[N],e[N],idx;

void init(){
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}

void add(int k,int x){
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx;
    idx++;
}

void remove(int k){
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main(){
    int n;
    scanf("%d",&n);
    init();
    while(n--){
        string op;
        int x,k;
        cin >> op;
        if(op == "L"){
            cin >> x;
            add(0,x);
        }else if (op == "R"){
            cin >> x;
            add(l[1],x);
        }else if(op == "D"){
            cin >> k;
            //k-1+2
            remove(k+1);
        }else if (op == "IL"){
            cin >> k >> x;
            add(l[k + 1],x);
        }else{
            cin >> k >> x;
            add(k+1,x);
        }
    }
    
    for(int i = r[0];i != 1;i = r[i]){
        cout << e[i] << ' ';
    }
    return 0;
}