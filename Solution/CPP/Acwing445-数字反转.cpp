#include <iostream>

//考虑bit的思想
using namespace std;

int main(){
    int in;
    bool flag = true;
    int out = 0;
    cin >> in;
    if(in < 0){
        flag = false;
        in = -in;
    }
    while(in > 0){
        int cur = in % 10;
        in = in / 10;
        out = out *10 + cur;
    }
    if(!flag){
        out = -out;
    }
    cout << out << endl;
    return 0;
}