#include <iostream>
#include <vector>

//高精度乘一个普通的数
using namespace std;


/*
高精度乘法的模板
// C = A * b, A >= 0, b > 0
vector<int> mul(vector<int> &A, int b)
{
    vector<int> C;

    int t = 0;
    for (int i = 0; i < A.size() || t; i ++ )
    {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }

    while (C.size() > 1 && C.back() == 0) C.pop_back();

    return C;
}

*/
vector<int> mul(vector<int> &A,int b){
    int t = 0;
    vector<int> C;
    for(int i =0;i < A.size();i++){
        //当前位置的数 == (A[i] * b + t(上一位的进位)) % 10
        //t是逐渐累加的
        t += A[i] * b;
        C.push_back(t % 10);
        //移除当前位置的数的影响，将进位变为下一位的(前一位是当前的10倍)
        t /= 10;
    }
    //t还剩下的话要继续进位， 0 < b 
    while(t){
        C.push_back(t % 10);
        t /= 10;
    }
    //b == 0的时候
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main(){
    string a;
    int b;
    vector<int> A;
    cin >> a >> b;
    for(int i = a.size() - 1;i >= 0;i--) A.push_back(a[i] - '0');

    auto C = mul(A,b);

    for(int i = C.size() - 1;i >= 0;i--){
        cout << C[i];
    }
    return 0;
}
