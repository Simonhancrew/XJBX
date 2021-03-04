#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> div(vector<int> &A,int b,int &r){
    vector<int> C;
    r = 0;
    //除法是从最高位开始的
    //如果不能整除b就将当前的余数乘10加下一位再尝试
    //因为可能存在先导0，所以结束之后还要做一个删除0的操作
    for(int i = A.size() - 1;i >= 0;i--){
        r = r * 10 + A[i];
        //记得除数是b
        C.push_back(r / b);
        r = r % b;
    }
    //不同于加减乘除，我们从最高位开始的，不考虑进位
    //push的顺序不一样，需要统一的，在这里逆序输出
    reverse(C.begin(),C.end());
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main(){
    string a;
    int b;
    vector<int> A;
    cin >> a >> b;
    for(int i = a.size() - 1;i >= 0;i--) A.push_back(a[i] - '0');
    //余数
    int r;
    auto C = div(A,b,r);
    for(int i = C.size() - 1;i >= 0;i--){
        cout << C[i];
    }   
    cout <<'\n'<< r;
    return 0;
}